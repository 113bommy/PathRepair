n,a,b=map(int,input().split())
if a+b-1>n:exit(print(-1))
if a*b<n:exit(print(-1))
ans=[]
c=0
nn=n
for i in range(a):
  ans.append([])
  t=0--nn//(a-i)
  if i==0:
    t=b
  nn-=min(t,b)
  for j in range(min(b,t)):
    ans[-1].append((i+1)*b-j)
    c+=1
    if c==n:break
  if c==n:break
anss=[]
for i in ans:anss+=i
def position_zip(a,flag):
  j=1
  d={}
  for i in sorted(a):
    if i in d:continue
    d[i]=j
    j+=1
  if flag==1:return d
  return [d[i] for i in a]
print(*position_zip(anss,0))