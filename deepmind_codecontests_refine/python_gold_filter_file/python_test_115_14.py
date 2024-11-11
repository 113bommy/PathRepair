# import collections
# import random
# import math
# import itertools
# import math
# mport math
# import bisect
from collections import defaultdict
# import itertools
# from sys import stdin, stdout
# import math
# import math
# import bisect
# import bisect
# import collections
# import itertools
# import math
import sys

# import operator
# from decimal import Decimal

# sys.setrecursionlimit(10**6)

class DisjointSet:
    parent = {}
    cp = {}
    # stores the depth of trees
    rank = {}
    m = 0

    # perform MakeSet operation
    def makeSet(self, universe):
        # create `n` disjoint sets (one for each item)
        for i in universe:
            self.parent[i] = i
            self.cp[i] = 1
            self.rank[i] = 0

    # Find the root of the set in which element `k` belongs
    def Find(self, k):
        # if `k` is not the root
        if self.parent[k] != k:
            # path compression
            self.parent[k] = self.Find(self.parent[k])
        return self.parent[k]

    # Perform Union of two subsets
    def Union(self, a, b):
        # find the root of the sets in which elements `x` and `y` belongs
        x = self.Find(a)
        y = self.Find(b)

        # if `x` and `y` are present in the same set
        if x == y:

            return

        # Always attach a smaller depth tree under the root of the deeper tree.
        if self.rank[x] > self.rank[y]:
            self.parent[y] = x
            self.cp[x] += self.cp[y]
            self.cp[y] = 0
            self.m = max(self.m, self.cp[x])
        elif self.rank[x] < self.rank[y]:
            self.parent[x] = y
            self.cp[y] += self.cp[x]
            self.cp[x] = 0
            self.m = max(self.m, self.cp[y])
        else:
            self.parent[x] = y
            self.rank[y] = self.rank[y] + 1
            self.cp[y] += self.cp[x]
            self.cp[x] = 0
            self.m = max(self.m, self.cp[y])


def printSets(universe, ds):
    print([ds.Find(i) for i in universe])


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


# mod = 10**9+7
# fval = [1]
# for i in range(1,200001):
#     x = (fval[-1]*i)%mod
#     fval.append(x)
#
# ifac = [1]*(200001)
# ifac[200000] = pow(fval[200000], -1, mod)
# for i in range(200000-1, 1, -1): ifac[i] = ifac[i+1]*(i+1)%mod


def drank(d, processing, da, rank):
    tmp = 10 ** 9
    if len(d[da]) == 1:
        return 1
    for di in d[da]:
        if processing[di - 1] == 0:
            processing[di - 1] = 1
            tmp = min(tmp, drank(d, processing, di, rank))
            processing[di - 1] = 0
    rank[da - 1] = tmp + 1
    return tmp + 1



def binary_search(n, a):
    l = len(a)
    low = 0
    high = l-1
    while high>=low:
        mid = (high+low)//2
        if a[mid] == n:
            return mid
        elif a[mid]>n:
            high = mid-1
        else:
            low = mid+1
    return -1

is_prime = [True]*(10**6+1)
def primeseive(n):
    is_prime[0] = is_prime[1] = False
    i = 2
    while i*i<=n:
        if is_prime[i] == True:
            for j in range(i*i,n+1,i):
                is_prime[j] = False
        i+=1

def satis(a, m):
    i = 0
    l = len(a)
    j = 1
    ans = 0
    while i<l:
        k = 0
        while j<l and a[j]< a[i]+m:
            j+=1
            k+=1
        if k==0:
            ans += m
            i+=1
            j+=1
        else:
            ans += (a[i+k]- a[i])
            i = i+k
            j = i+1
    return ans

def solve():
    n , h = li()
    a = li()
    if n == 1:
        return h
    if h<=n:
        return 1
    else:
        low = 1
        high = h
        m = 10**18

        while high>=low:
            mid = (low+high)//2
            x = satis(a,mid)
            if x>h:
                high = mid-1
                if x<m:
                    m = x
                    prev = mid
            elif x<h:
                low = mid+1
            else:
                return mid
        return prev






def main():
    #primeseive(10**6)
    #print(is_prime)
    for _ in range(ii()):
    #solve()
        sys.stdout.write(str(solve()) + "\n")
    # print(solve())

    #     z += str(ans) + '\n'
    # print(len(ans), ' '.join(map(str, ans)), sep='\n')
    # stdout.write(z)


# for interactive problems
# print("? {} {}".format(l,m), flush=True)
# or print this after each print statement
# sys.stdout.flush()


if __name__ == "__main__":
    main()