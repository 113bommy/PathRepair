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
    h,w,k = map(int,ipt().split())
    a = [input() for _ in range(h)]
    for i,ai in enumerate(a):
        if "S" in ai:
            si = i
            sj = ai.find("S")
            break
    q = queue.Queue()
    t = [[10**10]*w for _ in [0]*h]
    dir = [(-1,0),(1,0),(0,-1),(0,1)]
    t[si][sj] = 0
    q.put((si,sj))
    g1 = [(si,sj)]
    while not q.empty():
        qi,qj = q.get()
        for di,dj in dir:
            if 0 <= qi+di <= h-1 and 0 <= qj+dj <= w-1 and a[qi+di][qj+dj] == ".":
                if t[qi+di][qj+dj] > t[qi][qj] + 1:
                    t[qi+di][qj+dj] = t[qi][qj] + 1
                    g1.append((qi+di,qj+dj))
                    if t[qi][qj] != k-1:
                        q.put((qi+di,qj+dj))

    mi = 10**4
    for i,j in g1:
        if mi > (i+k-1)//k+1:
            mi = (i+k-1)//k+1
        if mi > (j+k-1)//k+1:
            mi = (j+k-1)//k+1
        if mi > (h-1-i+k-1)//k+1:
            mi = (h-1-i+k-1)//k+1
        if mi > (w-1-j+k-1)//k+1:
            mi = (w-1-j+k-1)//k+1
    print(mi)
    return

if __name__ == '__main__':
    main()
