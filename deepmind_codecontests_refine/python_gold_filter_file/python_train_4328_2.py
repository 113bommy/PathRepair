x = int(input())
t = 0
t1 = 0
k = 0
k1 = 0
i = 0
r = 0
r1 = 0
for i in range(1,x+1):
	a = list(map(int,input().split()))
	t = t + a[0]
	k = max(a[0]-a[1],k)
	if k == a[0] - a[1]:
		r = i
	t1 = t1 + a[1]
	k1 = max(a[1]-a[0],k1)
	if k1 == a[1] - a[0]:
		r1 = i
if t + k1 > t1  + k:
	print(r1)
else:
	print(r)

