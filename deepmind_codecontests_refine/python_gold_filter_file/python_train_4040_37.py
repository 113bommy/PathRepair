import heapq
n,m=map(int,input().split())
ab=[[0]*2 for _ in range(n)]


for i in range(n):
    ab[i]=list(map(int,input().split()))
ab.sort()
hq=[]
tmp=0
ans=0
for i in range(1,m+1):
    while tmp<n and ab[tmp][0]==i:
        heapq.heappush(hq,-ab[tmp][1])
        tmp+=1
    if hq:
        ans-=heapq.heappop(hq)
print(ans)
