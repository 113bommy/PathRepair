from math import log

a, b = input().split()
a = int(a); b = int(b)

def gcd(a, b):
	if a < b:
		return gcd(b, a)
	elif not a%b:
		return b
	else:
		return gcd(b, a%b)

def div_n(x, i):
	l = int(round(log(x)/log(i)))
	count = 0
	for j in range(1, l+1):
		if not x%i:
			x = x//i
			count += 1
	return (x, count)

if a == b:
	print(0)
else:
	n = gcd(a, b)
	num_a = a//n
	num_b = b//n

	(num_a, count1) = div_n(num_a, 2)
	(num_a, count2) = div_n(num_a, 3)
	(num_a, count3) = div_n(num_a, 5)
	count_a = count1+count2+count3

	(num_b, count1) = div_n(num_b, 2)
	(num_b, count2) = div_n(num_b, 3)
	(num_b, count3) = div_n(num_b, 5)
	count_b = count1+count2+count3

	if num_a == 1 and num_b == 1:
		print(count_a+count_b)
	else:
		print(-1)
