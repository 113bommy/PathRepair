n, m, q = map(int, input().split())
s = input()
t = input()
k = [0] * (n + 1)
cntr = 0
for i in range(1, n+1):
	k[i] = k[i-1]
	if s[i - 1:i + m - 1] == t: k[i] += 1
for i in range(q):
	l, r = map(int, input().split())
	print(k[max(l-1, r-m+1)]-k[l-1])
