import math
#import numpy as np
import queue
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)

def main():
    n,m = map(int,ipt().split())
    way = [[] for _ in range(n)]
    for _ in range(m):
        s,t = map(int, ipt().split())
        way[s].append(t)

    cos = [0]*(n+1)
    cos[n] = 0 * n
    for i in range(n-1,0,-1):
        nm = 0
        sm = 0
        for j in way[i]:
            nm += 1
            sm += 1+cos[j]
        cos[i] = sm/nm

    gm = cos[1]
    for i in range(1,n-1):
        nm = 0
        ma = 0
        sm = 0
        for j in way[i]:
            nm += 1
            sm += 1+cos[j]
            if ma < 1+cos[j]:
                ma = 1+cos[j]
        if nm == 1:
            continue
        else:
            cos[i] = (sm-ma)/(nm-1)
        for j in range(i-1,0,-1):
            nm = 0
            sm = 0
            for k in way[j]:
                nm += 1
                sm += 1+cos[k]
            cos[j] = sm/nm
#        print(cos)
        if cos[1] < gm:
            gm = cos[1]

    print(gm)


    return

if __name__ == '__main__':
    main()
