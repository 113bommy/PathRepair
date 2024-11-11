n, k, s = map(int, input().split())
if s == 10**9:
	a = [1] * n
else:
	a = [10**9] * n


for i in range(k):
	a[i] = s

print (*a)