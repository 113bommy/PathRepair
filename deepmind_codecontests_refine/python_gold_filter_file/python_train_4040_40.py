import heapq
n,m = map(int,input().split())
al = [[] for i in range(10**5)]
ans = 0
h = []
for i in range(n):
    a,b = map(int,input().split())
    al[a-1] += [-b]
for i in range(m):
    for j in al[i]:
        heapq.heappush(h,j)
    if h:
        ans -= heapq.heappop(h)
print(ans)