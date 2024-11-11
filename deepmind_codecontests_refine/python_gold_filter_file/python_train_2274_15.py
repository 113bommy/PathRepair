n,k = map(int,input().split())
a = list(map(int,input().split()))
from fractions import gcd
g = a[0]
for i in a[1:]:
    g = gcd(g,i)
if k<=max(a) and k%g==0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')