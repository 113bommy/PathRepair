def R(): return map(int, input().split())
def I(): return int(input())
def S(): return str(input())

def L(): return list(R())

from collections import Counter 

import math
import sys

from itertools import permutations

n=I()

cur=1

cnt=2
ans=0

while cnt<n:
    if cur<n//2:
        cur=n+1-cur
      
        cnt+=1
    elif cur==(n+1)//2:
        break
    else:
        cur=n+2-cur
      
        cnt+=1
        ans+=1

print(ans)