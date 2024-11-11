def gcd(a, b):

	if (b == 0): 
		return a 
	return gcd(b, a%b) 

t = int(input())

for ii in range(t):
	n = int(input())

	a = list(map(int, input().split()))

	b = sorted(a)

	m = min(a)

	ans = True

	for i in range(n):
		if a[i]!=b[i]:
			v = gcd(a[i], b[i])
			# print(v)
			if v%m != 0:
				ans = False
				break

	if ans:
		print("YES")
	else:
		print("NO")