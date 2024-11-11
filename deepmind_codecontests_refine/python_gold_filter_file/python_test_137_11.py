# import collections
# import random
# import math
# import itertools
# import math
# mport math
import bisect
# from collections import defaultdict
# import itertools
# from sys import stdin, stdout
# import math
# import math
# import bisect
# import bisect
# import collections
# import itertools
# import math
import collections
import itertools
import math
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


# mod = 10**9+7
# fval = [1]
# for i in range(1,200001):
#     x = (fval[-1]*i)%mod
#     fval.append(x)
#
# ifac = [1]*(200001)
# ifac[200000] = pow(fval[200000], -1, mod)
# for i in range(200000-1, 1, -1): ifac[i] = ifac[i+1]*(i+1)%mod
# _________________ For taking Input from the Text Files __________________
# import os.path
#
# if (os.path.exists('input.txt')):
#     sys.stdin = open("input.txt", "r")
#     sys.stdout = open("output.txt", "w")
#     sys.stderr = open("error.txt", "w")

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


def solve():
    a, b = li()
    if a == b: return "YES"
    bina = bin(a).lstrip('0b')
    binb = bin(b).lstrip('0b')
    la = len(bina)
    lb = len(binb)
    nza = bina.count('0')
    nzb = binb.count('0')
    if nzb > nza or (la-nza)> (lb-nzb):
        return "NO"
    if nza == 0:
            return "YES"
    if binb[-1] == '0':
        return "NO"
    if nzb == 0:
        if int(bina[-nza:], 2) != 0:
            return "NO"
        return "YES"


    for i in range(lb):
        if binb[i] == '0':
            fz = i
            break
    lz = fz
    for j in range(fz + 1, lb):
        if binb[j] == '0':
            lz = j
    same = binb[fz:lz + 1]
    rsame = same[::-1]
    nfo = fz
    nlo = lb - lz - 1


    y = bina.find(same)
    if y == -1:
        x = bina.find(rsame)
        if x == -1:
            return "NO"
        else:
            if '0' in bina[:x]: return "NO"
            right = bina[x + (lz - fz + 1):]
            if right == '': return "YES"
            right = right.rstrip('0')
            if '0' in right: return "NO"
            if nlo >= y and nfo >= len(right):
                return "YES"
            return "NO"
    else:
        if '0' in bina[:y]: return "NO"
        right = bina[y+(lz-fz+1):]
        if right =='': return "YES"
        right = right.rstrip('0')
        if '0' in right or right=='': return "NO"
        if nfo >= y and nlo >= len(right):
            return "YES"
        else:
            x = bina.find(rsame)
            if x == -1:
                return "NO"
            else:
                if '0' in bina[:x]: return "NO"
                right = bina[x + (lz - fz + 1):]
                if right == '': return "YES"
                right = right.rstrip('0')
                if '0' in right: return "NO"
                if nlo >= y and nfo >= len(right):
                    return "YES"
                return "NO"



def main():
    #primeseive(10**6)
    #print(is_prime)
    #for _ in range(ii()):
    print(solve())
        #sys.stdout.write(str(solve()) + "\n")
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