from itertools import accumulate as ac
o=[]
f=lambda l,r,v:lambda x:v if l<=x<=r else v+(l-x) if 0<=x<=l else v+(x-r)

o.extend([f(0,0,0)])
n=int(input())
*a,=map(int,input().split())
*b,=map(int,input().split())
*c,=ac([0]+a)

for (i,(t,v)) in enumerate(zip(a,b)):
  o.extend([f(c[i],c[i+1],v)])
o.extend([f(c[-1],c[-1],0)])
v=lambda s:min(map(lambda x:x(0.5*s),o))

S=0
for i in range(2*c[-1]):
  S+=0.25*(v(i)+v(i+1))
print(S)
