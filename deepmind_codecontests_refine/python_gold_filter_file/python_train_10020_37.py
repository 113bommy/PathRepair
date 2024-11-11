import sys, math
#from bisect import bisect_left as bl, bisect_right as br, insort
#from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
#from decimal import Decimal
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7

def main():

    for t in range(int(data())):
        n,x=mdata()
        cnt=0
        for i in range(n-1):
            u,v=mdata()
            if u==x or v==x:
                cnt+=1
        if cnt<=1:
            out("Ayush")
        else:
            if n%2==0:
                out("Ayush")
            else:
                out("Ashish")

if __name__ == '__main__':
    main()