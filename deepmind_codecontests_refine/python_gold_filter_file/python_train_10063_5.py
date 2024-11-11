from fractions import gcd
# from datetime import date, timedelta
from heapq import*
import math
from collections import defaultdict, Counter, deque
from bisect import *
import itertools
import fractions
# import sys
# sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7
# input = sys.stdin.readline


def main():
    # n = int(input())
    # b = list(map(int, input().split()))
    # if n <= 2 or max(b) - min(b)> 4:
    #     print(0)
    #     exit()
    # sa = []
    # for i in range(n-1):
    #     sa.append(b[i] - b[i + 1])
    # print(sa)

    # # for i in range(n-2):
    # #     if sa[i] > sa[i + 1]:
    # #         sa[i] -= 1
    # #         sa[i + 1] += 1
    # #     elif sa[i] < sa[i + 1]:
    # #         sa[i] += 1
    # #         sa[i + 1] -= 1
    # # print(sa)
    # ans = float("inf")
    # for i in range(min(b), max(b) + 1):
    #     v = 0
    #     for j in range(n - 1):
    #         if abs(i - sa[j]) == 4:
    #             v = float("inf")
    #             break
    #         else:


    #     ans = min(ans , v)


    n, k = map(int, input().split())
    r = list(map(int, input().split()))
    d = defaultdict(int)
    rr = set()
    Coun = Counter(r)
    for i in range(n):
        d[r[i]] += 1
        rr.add(r[i])
    rr = sorted(list(rr))
    l = [0] * n
    cnt = 0
    c = defaultdict(int)
    for i in range(len(rr)):
        c[rr[i]] = cnt
        cnt += Coun[rr[i]]
    
        

    ans = [0] * n
    for i in range(n):
        ans[i] = c[r[i]]
    # print(ans)
    for i in range(k):
        x, y = map(int, input().split())
        if r[x - 1] > r[y - 1]:
            ans[x - 1] -= 1
        elif r[x - 1] < r[y - 1]:
            ans[y - 1] -= 1
    print(*ans)




if __name__ == '__main__':
    main()
