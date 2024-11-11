import sys
n,m = map(int,input().split())
a=[]
for i in range(n):
	a.append(''.join(input().split()))
if n==1:
	print(1)
	sys.exit()
if n%2:
	print(n)
	sys.exit()
d=n//2
small=n
while d:
	i=d-1
	symmetry=True
	for j in range(d,2*d,1):
		if a[i] != a[j]:
			symmetry=False
			break
		i-=1
	if symmetry:
		small=d
	else:
		break
		
	if d%2:
		break
	d//=2

print(small)

