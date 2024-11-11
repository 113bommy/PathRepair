n,m=map(int,input().split())
l=list(map(int,input().split()))
# print(l)
z=[]
for i in range(1,n+1):
	for j in l:
		if j<=i:
			z.append(j)
			break
print(*z)