# coding: utf-8
import sys
#from operator import itemgetter
sysread = sys.stdin.buffer.readline
read = sys.stdin.buffer.read
#from heapq import heappop, heappush
from collections import defaultdict
sys.setrecursionlimit(10**7)
import math
#from itertools import product, accumulate, combinations, product
#import bisect
#import numpy as np
#from copy import deepcopy
#from collections import deque
#from decimal import Decimal

INF = 1 << 50



def run():
    N = int(input())
    lasts = defaultdict(lambda:[])
    lengths = set()
    S = []
    for i in range(N):
        s = input()
        S.append(s)
        lasts[s[1:]].append(i)
        lengths.add(len(s)-1)
    #print(lasts)
    #print(lengths)
    ans = 0
    for s in S:
        for l in lengths:
            if l == 0:
                if '' in lasts.keys():
                    for k in lasts['']:
                        if S[k][0] in s:
                            ans += 1
                            #print(s, l, S[k])
            else:
                if s[-l:] in lasts.keys():
                    for k in lasts[s[-l:]]:
                        if S[k][0] in s[:-l]:
                            ans += 1
                            #print(s, l, S[k])

    print(ans-N)



    

if __name__ == "__main__":
    run()