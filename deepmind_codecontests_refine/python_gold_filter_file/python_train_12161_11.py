n, m, c=map(int, input().split())
b=list(map(int, input().split()))
x=0
for _ in range(n):
	s=list(map(int, input().split()))
	z=c
	for i in range(m):
		z+=(s[i]*b[i])
	if z>0:
			x+=1
print(x)