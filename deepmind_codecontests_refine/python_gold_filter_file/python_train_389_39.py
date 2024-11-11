from sys import stdin, stdout
from math import gcd
N=10**6+2
n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
mp=[0]*N;not_pairwise=1
for v in a:
    mp[v]+=1
for i in range(2,N):
    if sum(mp[i::i])>1:
        not_pairwise=0
        break
g = a[0]
for v in a:
    g = gcd(g, v)
if not_pairwise:
    print('pairwise coprime')
elif g == 1:
    print('setwise coprime')
else:
    print('not coprime')