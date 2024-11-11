#import collections
# import random
# import math
#import itertools
#import math
#mport math
from collections import defaultdict
# import itertools
# from sys import stdin, stdout
#import math
import sys
# import operator
# from decimal import Decimal

# sys.setrecursionlimit(10**6)

p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def MI(): return map(int, sys.stdin.buffer.readline().split())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()
def li(): return [int(i) for i in input().split()]
def lli(rows): return [li() for _ in range(rows)]
def si(): return input()
def ii(): return int(input())
def ins(): return input().split()


def solve():
    mod = 10**9+7
    h,w = li(); r = li(); c= li()
    grid = [[0]*w for _ in range(h)]
    for i in range(h):
        if r[i]>0:
            for j in range(r[i]):
                grid[i][j] = 1
            if j+1<w:
                grid[i][j+1] =-1
        else:
            grid[i][0] = -1
    flag = 0
    for i in range(w):
        if c[i]>0:
            for j in range(c[i]):
                if grid[j][i] == -1:
                    print(0)
                    return
                grid[j][i] = 1
            if j+1<h:
                if grid[j+1][i] ==1:
                    print(0)
                    return
                grid[j+1][i] =-1
        else:
            if grid[0][i] == 1:
                print(0)
                return
            grid[0][i] = -1
    ans = 1
    for i in range(h):
        for j in range(w):
            if grid[i][j] == 0:
                ans = (ans*2)%mod
    print(ans)
    return

def main():
    solve()
    # for _ in range(II()):
    #     sys.stdout.write(str(solve()) + "\n")


    #     z += str(ans) + '\n'
    # print(len(ans), ' '.join(map(str, ans)), sep='\n')
    # stdout.write(z)


# for interactive problems
# print("? {} {}".format(l,m), flush=True)
# or print this after each print statement
# sys.stdout.flush()


if __name__ == "__main__":
    main()