from math import inf as inf
from math import *
from collections import *
import sys
from itertools import permutations
input=sys.stdin.readline
t=1
while(t):
    t-=1
    n=int(input())
    f=n-45*20*(10**19)%n
    print(f,f+(10**20-1))
    