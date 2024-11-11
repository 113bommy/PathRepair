from collections import defaultdict
import heapq
n,m=map(int,input().split())
dic=defaultdict(list)
for i in range(n):
    a,b=map(int,input().split())
    dic[a]+=[-b]
    
li=[]
ans=0

for i in range(1,m+1):
    if dic[i]:
        for j in dic[i]:
            heapq.heappush(li,j)
    if li:
        ans+=heapq.heappop(li)
print(-ans)