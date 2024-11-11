#! /usr/bin/python3 -s

def mcd(m, n):
	if n == 0:
		return m
	else:
		return mcd(n, m%n)

def lcm(m, n):
	return m * (n // mcd(m, n))

def recursive_lcm(top_val):

	result = 1
	alter_index = 1
	while result <= top_val:
		result = lcm(result, alter_index + 1)
		alter_index += 1

	# print(result)
	return(alter_index)

def main():
	[n ,k] = [int(x) for x in input("").split()]

	max_k =  recursive_lcm(10**18)

	dict = {}

	if k < max_k:
		max_k = k

	# if 1 == 1:
	# 	print('')

	# if n == k:
	# 	print('No')
	# 	return None

	for i in range(1, max_k + 1):
		try:
			dict[n%i]
		except Exception as e:
			dict[n%i] = True
		else:
			if dict[n%i]:
				print('No')
				return None
			else:
				pass

	
	print('Yes')
	return None

main()