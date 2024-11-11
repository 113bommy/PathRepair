n,k=map(int,input().split())
l=[]
j=1
l=[i for i in range(1,k+2)]	
l.sort(reverse=True)
m=k+2
for j in range(n-len(l)):
	l.append(m)
	m=m+1
print(*l)