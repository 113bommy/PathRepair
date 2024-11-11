import math
import sys
from collections import Counter
from math import factorial as fact
from collections import defaultdict
def inpint():
    return int(input())
def inpstr():
    return str(input())
def inparr():
    return list(map(int,input().strip().split()))
def inptup():
    return map(int,input().strip().split())

#----------------------------------------------------------------------------
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    if a[0]+a[1]<=a[-1]:
        print(1,2,n)
    else:
        print(-1)