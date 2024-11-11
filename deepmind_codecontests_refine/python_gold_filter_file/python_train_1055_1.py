import heapq
n,k=map(int,input().split())
b_l=[]
for _ in range(n):
    t,b=map(int,input().split())
    b_l.append([b,t])
b_l.sort(reverse=True)
##print(b_l)
ans=0
sum_fg=0
h=[]
heapq.heapify(h)
for i in range(n):
    sum_fg+=b_l[i][1]
    heapq.heappush(h,b_l[i][1])
    while(len(h)>k):
        g=heapq.heappop(h)
        sum_fg-=g
    beauty=b_l[i][0]
    ##print(h)
    ans=max(ans,sum_fg*beauty)
print(ans)
