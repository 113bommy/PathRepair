n = int(input())
a = input().split()
for i in range(n):
	a[i] = int(a[i])
minE = 1000000000
for x in range(1,n+1):
	e = 0
	for f in range(1,n+1):
		e += (abs(x-f) + f-1 + x-1)*a[f-1]*2
	if e < minE:
		minE = e
print(minE)
