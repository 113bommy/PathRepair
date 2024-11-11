n,k=map(int,input().split())
x=list(map(int,input().split()))
dd=[0]*1000001
for i in x:
  c=max(0,i-k)
  dd[c]+=1
  dd[i]-=1
erase=[False]*1000001
s=0
for i in range(1000001):
  s+=dd[i]
  if s>0: erase[i]=True
ans=0
for i in x:
  if erase[i]:ans+=1
print(n-ans)