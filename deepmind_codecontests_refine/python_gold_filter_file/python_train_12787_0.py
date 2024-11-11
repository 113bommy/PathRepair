import math
#import numpy as np
import queue
from collections import deque,defaultdict
import heapq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)

def main():
    n = int(ipt())
    way = [[] for i in range(n)]
    for _ in [0]*(n-1):
        a,b = map(int,ipt().split())
        way[a].append(b)
        way[b].append(a)
    rt = -1
    for i in range(n):
        if len(way[i]) > 2:
            rt = i
            break

    def dp(pp,np):
        sum = 0
        n0 = 0
        for i in way[np]:
            if i == pp:
                continue
            tmp = dp(np,i)
            sum += tmp
            if tmp == 0:
                n0 += 1
        if n0 > 1:
            sum += n0-1
        return sum

    if rt == -1:
        print(1)
        exit()
    else:
        print(dp(-1,rt))

    return

if __name__ == '__main__':
    main()
