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
    n = int(ipt())
    ga,sa,ba = map(int,ipt().split())
    gb,sb,bb = map(int,ipt().split())

    dp = [0]*(5005)
    for i in range(n+1):
        dp[i] = dp[i-1]
        if i >= ga and dp[i] < (gb-ga)+dp[i-ga]:
            dp[i] = gb-ga+dp[i-ga]
        if i >= sa and dp[i] < (sb-sa)+dp[i-sa]:
            dp[i] = sb-sa+dp[i-sa]
        if i >= ba and dp[i] < (bb-ba)+dp[i-ba]:
            dp[i] = bb-ba+dp[i-ba]
    ni = n+dp[n]

    dp = [0]*max(5005,ni+5)
    for i in range(ni+1):
        dp[i] = dp[i-1]
        if i >= gb and dp[i] < (ga-gb)+dp[i-gb]:
            dp[i] = ga-gb+dp[i-gb]
        if i >= sb and dp[i] < (sa-sb)+dp[i-sb]:
            dp[i] = sa-sb+dp[i-sb]
        if i >= bb and dp[i] < (ba-bb)+dp[i-bb]:
            dp[i] = ba-bb+dp[i-bb]
    print(ni+dp[ni])

    return None

if __name__ == '__main__':
    main()
