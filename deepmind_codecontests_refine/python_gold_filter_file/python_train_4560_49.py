n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
f = sorted(list(map(int, input().split())), reverse=True)

ok, ng = a[-1]*f[0], -1
while ok-ng > 1:
	x = (ok+ng)//2
	tmp = 0
	for i in range(n):
		tmp += max(0, a[i] - x//f[i])
	if tmp > k:
		ng = x
	else:
		ok = x
print(ok)
