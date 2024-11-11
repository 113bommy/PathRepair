from bisect import*
def solve(x):
  s=t=0
  i=n
  j=-1
  for y in a:
    while i and a[i-1]*y>x:i-=1
    while j+1<m and b[j+1]*y<=x:j+=1
    s+=j+1
    t+=i
    if y*y<=x:t-=1
  s+=t//2
  t=0
  i=m
  for y in c:
    while i and c[i-1]*y>x:i-=1
    t+=i
    if y*y<=x:t-=1
  s+=t//2
  return s
n,k,*t=map(int,open(0).read().split())
t.sort()
i=bisect(t,0)
a,b,c=t[i:],t[:i],t[i-1::-1]
n,m=len(a),len(b)
ok=10**18
ng=-ok
while ok-ng>1:
  mid=(ok+ng)//2
  if solve(mid)>=k:ok=mid
  else:ng=mid
print(ok)