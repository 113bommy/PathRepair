n,k,p,x,y=map(int,input().split())
a=[]
s=input().split()
for i in range(k):
	a+=[int(s[i])]
	
z=(n+1)//2

r=0
v=0

for i in range(k):
	v+=a[i]
	if a[i]>=y:r+=1

q=k-r
if q>=z:print(-1)
else:
	h=min(z-1-q,n-k)
	c=n-k-h
	if h+y*c+v>x:print(-1)
	else:
		for i in range(h):
			print("1",end=" ")
		for i in range(c):
			print(str(y),end=" ")