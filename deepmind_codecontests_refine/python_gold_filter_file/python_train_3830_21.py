n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
am=[]
ap=[]
zc=0
for i in a:
  if i<0:
    am.append(i)
  elif i>0:
    ap.append(i)
  else:
    zc+=1
am.sort()
ap.sort()
#print(am,ap)
def count(n,m,p,z):
  mx=-10**20
  lm=len(m)
  lp=len(p)
  if n==0:
    if z or (lm and lp):
      return (lm*lp+(lm+lp)*z+(z*(z-1))//2,0 if z else m[-1]*p[0])
    else:
      return (0,0)
  elif n<0:
    r=0
    j=0
    for i in m:
      while j<len(p) and i*p[j]>n:
        j+=1
      if j<len(p) and mx<i*p[j]:
         mx=i*p[j]
      r+=len(p)-j
    return (r,mx)
  else:
    if z or (lm and lp):
      mx=0 if z else m[-1]*p[0]
    r=lm*lp+(lm+lp)*z+(z*(z-1))//2
    j=lp-1
    for i in range(lp):
      while j>i and p[i]*p[j]>n:
        j-=1
      if j>i and p[i]*p[j]>mx:
        mx=p[i]*p[j]
      r+=j-i
      if i==j:
        break
    j=lm-1
    for i in range(lm):
      while j>i and m[i]*m[j]<=n:
        j-=1
      if i>j:
        j=i
      if j<lm-1 and m[i]*m[j+1]>mx:
        mx=m[i]*m[j+1]
      r+=lm-j-1
    return (r,mx)

r=10**18
t=0
s=set()

while True:
  ret=count(t,am,ap,zc)
  #if r<100:
  #  print(t,ret)
  if ret[0]<k:
    s.add(t)
    t+=r
    r=(r+1)//2
  elif ret[0]==k:
    print(ret[1])
    break
  else:
    if t in s:
      print(ret[1])
      break
    s.add(t)
    t-=r
    r=(r+1)//2
  
  
  
  