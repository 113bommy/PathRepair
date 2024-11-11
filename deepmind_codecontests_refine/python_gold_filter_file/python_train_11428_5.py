n,x,m=map(int,input().split())
sm=[-1 for i in range(m)]+[0]
w=[-1 for i in range(m)]
d=[m]
a=x
t=0
s=0
while True:
  s+=a
  if w[a]!=-1:
    inter=t-w[a]
    fv=w[a]
    ls=d[(n-fv)%inter+fv]
    lls=d[w[a]]
    print(sm[lls]+(n-fv)//inter*(s-sm[a])+(sm[ls]-sm[lls]))
    break
  w[a]=t
  d.append(a)
  sm[a]=s
  t+=1
  a=(a*a)%m