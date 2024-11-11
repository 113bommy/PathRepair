n,m=map(int,input().split())
AB=[]
append=AB.append
for i in range(m):
  a,b=map(int,input().split())
  append([a,b])
AB.sort(key=lambda x:x[1])
c,ans=0,0
for a,b in AB:
  if a>=c:
    ans+=1
    c=b
print(ans)
