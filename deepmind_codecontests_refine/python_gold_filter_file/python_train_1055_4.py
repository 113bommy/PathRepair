from heapq import *
n,k =map(int,input().split())
l=[tuple(map(int,input().split())) for i in range(n)]
l.sort(key= lambda x: x[1])
s=[0]*(k)
kmin=0
sumi=0
res=0
for i in range(1,len(l)+1):
	sumi+=l[-i][0]
	heappush(s,l[-i][0])
	sumi-=heappop(s)
	res=max(res,sumi*l[-i][1])
print(res)

