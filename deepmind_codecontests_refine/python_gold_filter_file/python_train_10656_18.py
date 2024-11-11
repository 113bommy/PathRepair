n=int(input())
m=10000000000000000
z=-1
a=[]
for i in range(n):
	x,y=map(int,input().split())
	m=min(m,x)
	z=max(z,y)
	a.append([x,y])
for i in range(len(a)):
	if a[i][0]==m and a[i][1]==z:
		print(i+1)
		break
else:
	print(-1)