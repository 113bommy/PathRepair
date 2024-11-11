n=int(input())
l=[]
l.append(n)
for i in range(1,n):
	l.append(i)
print(*l)