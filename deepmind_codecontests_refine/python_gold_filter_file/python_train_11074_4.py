def gen_prime(n):
	num = [0 for i in range(n+1)]
	num[2] = 1
	num[3] = 1
	for i in range(4, n+1):
		isprime = True
		for j in range(2, int(i**0.5)+1):
			if num[j]:
				if not i%j:
					isprime = False
					break
		if isprime:
			num[i] = 1

	prime = []
	for i in range(2, n+1):
		if num[i]:
			prime.append(i)

	return prime

n, m = map(int, input().split())
prime = gen_prime(10**5+100)

def closest(x):
	l = 0; r = len(prime)-1
	while l < r:
		mid = (l+r)//2
		if prime[mid] == x:
			return prime[mid]
		elif prime[mid] > x:
			r = mid
		else:
			l = mid+1
	return prime[l]


a = [0 for i in range(n)]
for i in range(n):
	a[i] = [int(i) for i in input().split()] 

diff = [[0 for i in range(m)] for i in range(n)]
for i in range(n):
	for j in range(m):
		diff[i][j] = closest(a[i][j]) - a[i][j]


min_sum = (10**5)*m
for i in range(n):
	temp = sum(diff[i])
	if temp < min_sum:
		min_sum = temp

total = min_sum

min_sum = (10**5)*n
for i in range(m):
	temp = 0
	for j in range(n):
		temp += diff[j][i]
	if temp < min_sum:
		min_sum = temp

print(min(total,min_sum))