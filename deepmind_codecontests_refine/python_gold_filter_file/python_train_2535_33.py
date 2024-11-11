n=int(input())
a=[]
a.append(n)
for i in range(1,n):
	a.append(i)
print(*a)