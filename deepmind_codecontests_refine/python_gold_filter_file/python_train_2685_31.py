N, M = map(int,input().split())
A = list(map(int,input().split()))
# 17:22

import sys
from math import gcd
def lcm(a,b):
    return a//gcd(a,b)*b
#%%
ans = 0
L = 1
for i in range(N):
    L = lcm(L, A[i])
    if L>2*M:
        print(0)
        sys.exit()

L2 = L
L1 = L//2
for a in A:
    if (L//a)&1==0:
        print(0)
        sys.exit()
ans = M//L1 - M//L2
print(ans)
