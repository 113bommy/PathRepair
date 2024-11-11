import heapq
N=int(input())
a=list(map(int,input().split()))
earl=[]
late=[]
for i in range(N):
  heapq.heappush(earl,a[i])
  heapq.heappush(late,-a[2*N+i])
E=0
L=0
for i in range(N):
  E+=a[i]
  L-=a[2*N+i]
e=[E]*(N+1)
l=[L]*(N+1)
for i in range(N):
  e[i+1]=e[i]+a[N+i]-heapq.heappushpop(earl,a[N+i])
  l[N-1-i]=l[N-i]-a[2*N-1-i]-heapq.heappushpop(late,-a[2*N-1-i])

ans=e[N]+l[N]
for i in range(N):
  ans=max(ans,e[i]+l[i])
print(ans)