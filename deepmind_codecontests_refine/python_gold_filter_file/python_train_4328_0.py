# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
n=int(input())
z=0
a=[]
x,y=0,0
for i in range(n):
	l,r=map(int,input().split())
	a.append((l,r))
	x+=l
	y+=r
m=abs(x-y)
for i in range(n):
	k=abs((x-a[i][0]+a[i][1])-(y-a[i][1]+a[i][0]))
	if k>m:
		z=i+1
		m=k
print(z)		



