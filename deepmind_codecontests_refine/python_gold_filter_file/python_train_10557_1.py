
n,k=input().split()

n=int(n)
k=int(k)
l=[]
l.append(0)
for i in range(1,2*n+1):
	l.append(i)
for i in range(1,k+1):
	x=2*i-1
	y=2*i
	l[x],l[y]=l[y],l[x]
for i in range(1,2*n+1):
	print(l[i],end=" ")