n,m=map(int,input().split())
list=[0]*n
for i in range(m):
	a,b=map(int,input().split())
	list[a-1]+=1
	list[b-1]+=1
for j in range(n):
	print(list[j])