l = int(input())
a = [*map(int, input().split())]

p = n = 0

for i in a:
	if i > 0:
		p += 1
	else:
		n += 1

ans = 0
if p and n:
	a.sort()
	for i in a:
		if i < 0:
			ans -= i
		else:
			ans += i
elif p:
	a.sort()
	ans -= a[0]
	for i in a[1:]:
		ans += i
else:
	a.sort(reverse=True)
	ans += a[0]
	for i in a[1:]:
		ans -= i

print(ans if l > 1 else a[0])