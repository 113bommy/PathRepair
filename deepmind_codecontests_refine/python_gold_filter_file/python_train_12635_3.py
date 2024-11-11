from heapq import * 
n,k=map(int,input().split())
a = list(map(int , input().split()))
for i in range(k):
    heappush(a,-heappop(a))
print(sum(a))