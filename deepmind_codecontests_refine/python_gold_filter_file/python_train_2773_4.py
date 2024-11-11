import bisect
import collections
import copy
import functools
import heapq
import itertools
import math
import random
import re
import sys
import time
import string
from typing import List, Mapping
sys.setrecursionlimit(999999)

x = int(input())
h,m = map(int,input().split())

ans = 0
while "7" not in str(h)+str(m) and ans<x*3600//math.gcd(x,3600):
    ans+=1
    m-=x
    if m<0:
        m+=60
        h-=1
        if h<0:
            h+=24
print(ans if ans<x*3600//math.gcd(x,3600) else -1)