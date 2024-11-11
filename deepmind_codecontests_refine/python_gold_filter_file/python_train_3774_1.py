#import math
#from functools import lru_cache
#import heapq
#from collections import defaultdict
#from collections import Counter
#from sys import stdout
#from sys import setrecursionlimit
from sys import stdin
input = stdin.readline
for Ti in range(int(input().strip())):
    n, m = [int(x) for x in input().strip().split()]
    sa = []
    for ni in range(n):
        sa.append(input().strip())
    s1 = sa[0]
    val = True
    ans = ''
    for m1 in range(m):
        for ci in list('abcdefghijklmnopqrstuvwwxyz'):
            s1 = sa[0]
            s1 = s1[:m1] + ci + s1[m1+1:]
            #print(s1)
            val = True
            for ni in range(n):
                dc = 0
                for mi in range(m):
                    if(sa[ni][mi]!=s1[mi]): dc+=1
                if(dc>1):
                    val=False
                    break
            if val:
                ans = s1
                break
        else:
            continue
        break
    if not ans:
        print('-1')
    else:
        print(ans)
