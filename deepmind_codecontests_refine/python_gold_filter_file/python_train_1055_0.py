import heapq as q
n,k=[int(x) for x in input().split()]
h=[]
a=[]
for i in range(n):
    a.append(list(map(int,input().split())))
a.sort(reverse=True,key=lambda x:x[1])
s=0
ans=0
for l,r in a:
    s+=l
    q.heappush(h,l)
    if len(h)>k:
        s-=q.heappop(h)
    ans=max(ans,s*r)
print(ans)
