from math import *
from collections import *
from itertools import *
from functools import *
from bisect import *
from heapq import *
from operator import *
from sys import *
setrecursionlimit(100000000)


for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    ans = l.count(1)*(2**l.count(0))
    print(ans)
    