n,m=map(int,input().split())
h=list(map(int,input().split()))
tall=[0]*n
for i in range(m):
  a,b=map(int,input().split())
  a-=1
  b-=1
  tall[a]=max(tall[a],h[b])
  tall[b]=max(tall[b],h[a])
res=0
for i in range(n):
  if h[i]>tall[i]:
    res+=1
print(res)