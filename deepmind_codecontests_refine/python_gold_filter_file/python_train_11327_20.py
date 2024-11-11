n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
bc=[list(map(int,input().split()))[::-1]for _ in range(m)]+[[0,1000000000000]]
bc.sort(reverse=1)
t=[]
for c,b in bc:
  for _ in range(b):
    t.append(c)
    if len(t)>=n:break
ans=0
for i in range(n):ans+=max(a[i],t[i])
print(ans)