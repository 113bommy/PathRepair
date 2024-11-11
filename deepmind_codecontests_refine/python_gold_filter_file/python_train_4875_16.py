n,m=map(int,input().split())
itv=[]
for i in range(m):
  a,b=map(int,input().split())
  start=min(a,b)
  end=max(a,b)
  itv.append([end,start])
t,ans=0,0
itv=sorted(itv)
for e,s in itv:
  if t<=s:
    t=e
    ans+=1
print(ans)