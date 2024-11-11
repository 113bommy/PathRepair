try:
        import sys
        from functools import lru_cache, cmp_to_key
        from heapq import merge, heapify, heappop, heappush
        # from math import *
        from collections import defaultdict as dd, deque, Counter as C
        from itertools import combinations as comb, permutations as perm
        from bisect import bisect_left as bl, bisect_right as br, bisect, insort
        from time import perf_counter
        from fractions import Fraction
        import copy
        from copy import deepcopy
        import time
        starttime = time.time()
        mod = int(pow(10, 9) + 7)
        mod2 = 998244353

        def data(): return sys.stdin.readline().strip()
        def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
        def L(): return list(sp())
        def sl(): return list(ssp())
        def sp(): return map(int, data().split())
        def ssp(): return map(str, data().split())
        def l1d(n, val=0): return [val for i in range(n)]
        def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]
        def A2(n,m): return [[0]*m for i in range(n)]
        def A(n):return [0]*n
        # sys.setrecursionlimit(int(pow(10,6)))
        # from sys import stdin
        # input = stdin.buffer.readline
        # I = lambda : list(map(int,input().split()))
        # import sys
        # input=sys.stdin.readline
        

        sys.stdin = open("input.txt", "r")
        sys.stdout = open("output.txt", "w")
except:
        pass



for _ in range(L()[0]):
        X = input().split()
        n = int(X[0])
        c = X[1]

        s = input()
        i = n-1
        if c not in s:
                print(2)
                print(n-1,n)
        elif s.count(c)==n:
                print(0)
        else:
                while(s[i]!=c):
                        i-=1
                i+=1
                if i*2<=n:
                        print(2)
                        print(n-1,n)
                else:
                        print(1)
                        print(i)
