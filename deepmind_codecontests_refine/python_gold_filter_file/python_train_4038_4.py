n,m,x=map(int,input().split())
c=[]
a=[]
for _ in range(n):
  ca=list(map(int,input().split()))
  c.append(ca[0])
  a.append(ca[1:])
ans=13*pow(10,5)
for i in range(2**n):
  rikai=[0]*m
  kin=0
  for j in range(n):
    if ((i>>j) & 1):#立っているビットのところで処理が走る
      for k in range(m):
        rikai[k]+=a[j][k]
      kin+=c[j]
  if min(rikai)>=x:
    ans=min(ans,kin)
print(ans if ans<13*pow(10,5) else -1)