import math
import sys
from collections import defaultdict

# input = sys.stdin.readline
rt = lambda: map(int, input().split())
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))


def main():
    n = ri()
    a = rl()
    if len(set(a)) == n:
        print(0)
    else:
        res = n
        pref = set()
        for i in range(n):
            if i > 0:
                if a[i-1] in pref:
                    break
                pref.add(a[i-1])

            suff = set()
            for j in range(n-1, i-1, -1):
                if j < n-1:
                    if a[j+1] in suff or a[j+1] in pref:
                        break
                    suff.add(a[j+1])
                res = min(res, j-i+1)
        print(res)


if __name__ == '__main__':
    main()
