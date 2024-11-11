n=int(input())
a=list(map(int,input().split()))
l=[0]*3*n
r=[-1000000000000000]*3*n
from heapq import heappop,heappush
h=[]
s=0
for i in a[:n]:
  heappush(h,i)
  s+=i
l[n-1]=s
for i in range(n,2*n):
  heappush(h,a[i])
  s+=a[i]
  s-=heappop(h)
  l[i]=s
h=[]
s=0
for i in a[2*n:]:
  heappush(h,-i)
  s+=-i
for i in range(2*n-1,n-2,-1):
  r[i]=s
  heappush(h,-a[i])
  s+=-a[i]
  s-=heappop(h)
print(max(l[i]+r[i]for i in range(3*n)))