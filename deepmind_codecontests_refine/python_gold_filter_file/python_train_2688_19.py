a,s=map(int,input().split())
sa,ss=[input() for i in range(2)]
if a<s:
    a,s=s,a
    sa,ss=ss,sa
from fractions import gcd
g=gcd(a,s)
x,y=a//g,s//g
for i in range(g):
    if sa[x*i]!=ss[y*i]:print(-1);break
else:print(x*s)