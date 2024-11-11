n,m=map(int,input().split())
arr=list(map(int,input().split()))
if n>m:
	print("YES")
	exit()
p=[0]*(1010)
for i in range(len(arr)):
	q=[0]*(1010)
	arr[i]%=m 
	q[arr[i]]+=1
	for j in range(m):
		if p[j]:
			q[(j+arr[i])%m]+=1
	# print(q)
	for j in range(m):
		p[j]+=q[j]
if p[0]:
	print("YES")
	exit()
print("NO")