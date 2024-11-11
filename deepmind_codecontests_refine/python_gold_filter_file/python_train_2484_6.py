n = int(input())
a = [int(input()) for _ in range(n)]
gr = 0
for x in a:
	gr ^= x
exist = set()
for i in range(n):
	cnt = 0
	while (a[i]>>cnt)&1 == 0:
		cnt += 1
	exist.add(cnt)
ok = True
ans = 0
for i in range(35, -1, -1):
	if (gr>>i)&1:
		if i not in exist:
			ok = False
		else:
			gr %= (1<<(i+1))
			gr = (1<<(i+1)) - gr - 1
			ans += 1
	else:
		gr %= (1<<(i+1))
if ok:
	print(ans)
else:
	print(-1)