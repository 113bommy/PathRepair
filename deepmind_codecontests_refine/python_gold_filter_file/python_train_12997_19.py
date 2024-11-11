import heapq
n= int(input())
a = list(map(int, input().split( )))

pre = sum(a[:n])
post = -sum(a[2*n:])
post2 = post
ans = - pre + post

Q = []
for i in range(n):
    heapq.heappush(Q, a[i])

S_pre = [pre]

for i in range(n,2*n):
    pre += a[i]
    heapq.heappush(Q,a[i])
    q = heapq.heappop(Q)
    pre -= q
    S_pre.append(pre)

Q2 = []
for i in range(2*n,3*n):
    heapq.heappush(Q2, -a[i])
S_post = [post]
for i in range(2*n - 1,n-1,-1):
    post -= a[i]
    heapq.heappush(Q2,-a[i])
    q = heapq.heappop(Q2)
    #print(q)
    post -= q
    S_post.append(post)

#print(S_pre)
#print(S_post)
for i in range(n+1):###+1
    ans = max(ans, S_pre[n-i]+S_post[i])
print(ans)


