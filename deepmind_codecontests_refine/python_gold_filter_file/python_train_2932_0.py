import collections
# import random
# import math
#import itertools
#import math
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

def findroot(x, parents):
    if parents[x] == x:
        return x
    else:
        result = findroot(parents[x],parents)
        parents[x] = result
        return result

def unionset(x,y,ranks, parents):
    x_root = findroot(x,parents)
    y_root = findroot(y, parents)

    if x_root == y_root:
        return
    if ranks[x_root]> ranks[y_root]:
        parents[y_root] = x_root
    elif ranks[y_root]> ranks[x_root]:
        parents[x_root] = y_root
    else:
        if x_root<y_root:
            parents[y_root] = x_root
            ranks[x_root] +=1
        else:
            parents[x_root] = y_root
            ranks[y_root] +=1



def solve():
    n,m = LI()
    parents = list(range(n+1))
    ranks = [0]*(n+1)
    #print(parents)
    for i in range(m):
        tmp = LI()
        if tmp[0]>1:
            for i in range(tmp[0]-1):
                unionset(tmp[i+1], tmp[i+2], ranks, parents)

    for i in range(1,n+1):
        findroot(i, parents)
    d = defaultdict(int)
    for j in parents[1:]:
        d[j]+=1
    ans = ''
    for i in range(1,n+1):
        ans+= str(d[parents[i]])+ ' '

    print(ans)


def main():
    # for _ in range(ii()):
    #     sys.stdout.write(str(solve()) + "\n")
    solve()


    #     z += str(ans) + '\n'
    # print(len(ans), ' '.join(map(str, ans)), sep='\n')
    # stdout.write(z)


# for interactive problems
# print("? {} {}".format(l,m), flush=True)
# or print this after each print statement
# sys.stdout.flush()


if __name__ == "__main__":
    main()