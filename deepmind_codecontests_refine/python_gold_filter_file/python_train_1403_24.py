n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
d = {}
ans = []

for i in range(len(a)):
	d[i + 1] = a[i]

x = list(d.values())
x.sort()

for i in x:
	k -= i
	if k >= 0:
		ans.append(list(d.values()).index(i) + 1)
		d[list(d.values()).index(i) + 1] = 0
	else:
		break
		

print(len(ans))
for i in ans:
	print(i, end=' ')
