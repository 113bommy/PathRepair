def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**7)
    from collections import Counter, deque
    from itertools import combinations, permutations, accumulate, groupby, product
    from bisect import bisect_left,bisect_right
    from heapq import heapify, heappop, heappush
    import math
    #from math import gcd
 
    #inf = 10**17
    #mod = 10**9 + 7

    t = int(input())
    alphabet = 'abcdefghijklmnopqrstuvwxyz' #26
    for _ in range(t):
        n,m = map(int, input().split())
        s = [list(input().rstrip()) for _ in range(n)]
        res = -1
        for i in range(m):
            if res != -1:
                continue
            temp = s[0][::]
            for j in range(26):
                if res != -1:
                    continue
                temp[i] = alphabet[j]
                for k in range(1, n):
                    diff = 0
                    for c in range(m):
                        if temp[c] != s[k][c]:
                            diff += 1
                    if diff >= 2:
                        break
                else:
                    res = temp
        if res == -1:
            print(-1)
        else:
            print(''.join(res))

if __name__ == '__main__':
    main()