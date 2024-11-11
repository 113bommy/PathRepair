from functools import reduce
from fractions import gcd
import math
import bisect
import itertools
import sys
sys.setrecursionlimit(10000000)
input = sys.stdin.readline
INF = float("inf")


# update: node[x] を更新する
# getmin: 区間 [a, b) の最小値を返す
class SegmentTree:
    def __init__(self, arr):
        size = len(arr)
        n = 1 << size.bit_length()
        self.n = n
        self.node = [0]*(2*n - 1)
        for i in range(size):
            self.node[i+n-1] = arr[i]
        for i in reversed(range(n-2)):
            self.node[i] = max(self.node[2*i+1], self.node[2*i+2])
    
    def update(self, x, val):
        x += (self.n - 1)
        self.node[x] = val
        while x > 0:
            x = (x - 1) // 2
            self.node[x] = max(self.node[2*x+1], self.node[2*x+2])
    
    def getmax(self, l, r):
        res = 0
        l += self.n - 1
        r += self.n - 1
        while l <= r:
            res = max(res, self.node[l])
            res = max(res, self.node[r])
            l  = l // 2
            r = r // 2 - 1
        return res
 

# 処理内容
def main():
    N, K = map(int, input().split())
    
    seg = SegmentTree([0]*300010)
    ans = 0
    for _ in range(N):
        A = int(input())
        a = max(A-K, 0)
        b = min(A+K, 300000)
        tmp = seg.getmax(a, b) + 1
        ans = max(ans, tmp)
        seg.update(A, tmp)
    
    print(ans)


if __name__ == '__main__':
    main()