k = {}
n = int(input())
a = input().split()
for i in range(n):
	a[i] = int(a[i])
	if a[i] not in k:
		k[a[i]] = 1
a.sort()
l = list(k.keys())
l.sort()

if len(l) == 3 and 2 * l[1] == l[0] + l[2]:
	print(l[1] - l[0])
elif len(l) == 2 and (((l[0] + l[1]) % 2) == 0):
	print((l[1] - l[0])//2)
elif len(l) == 2:
	print(l[1] - l[0])
elif len(l) == 1:
	print(0)
else:
	print(-1)