def R(): return map(int, input().split())
def I(): return int(input())
def S(): return str(input())

def L(): return list(R())

from collections import Counter 

import math
import sys


from itertools import permutations

n,m=R()

a=list(map(str, input().split()))

b=list(map(str, input().split()))

ans=['']*2020

for i in range(n*m):
    ans[i]=a[i%n]+b[i%m]

for _ in range(I()):
    j=(I()-1)%(n*m)
    print(ans[j])


#


