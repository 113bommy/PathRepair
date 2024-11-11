n,l2,c=int(input()),[0],0
l1=list(map(int,input().split()))
a,b=map(int,input().split())
l=l2+l1
for i in range(n):
	if i>a-1 and i<=b-1:
		c+=l[i]
print(c)