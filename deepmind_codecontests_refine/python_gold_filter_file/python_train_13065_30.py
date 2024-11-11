n,m=map(int,input().split())
cnt=0
for i in range(n):
	a=list(map(int,input().split()))
	for i in range(0,2*m,2):
		if a[i]==1 or a[i+1]==1:
			cnt+=1
print(cnt)
