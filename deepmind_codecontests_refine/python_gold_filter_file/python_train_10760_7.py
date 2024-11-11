
n,k=list(map(int,input().split()))
req=list(map(int,input().split()))
req.append("fake")
idx=0
ans=[req[0]]
hashSet=set(req)

for i in range(1,n*k+1):
	if i not in hashSet:
		ans.append(i)
	if len(ans)==n:
		print(*ans)
		idx+=1
		ans=[req[idx]]
