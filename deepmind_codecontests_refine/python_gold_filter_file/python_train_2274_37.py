from fractions import gcd
n,k = map(int,input().split())
a = list(map(int,input().split()))
G = a[0]
for i in a:
    G = gcd(G,i)
if k<=max(a) and k%G==0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
