from collections import defaultdict, Counter
from bisect import bisect, bisect_left
from math import sqrt, gcd, ceil, factorial
from heapq import heapify, heappush, heappop


MOD = 10**9 + 7
inf = float("inf")
ans_ = []

def nin():return int(input())
def ninf():return int(file.readline())

def st():return (input().strip())
def stf():return (file.readline().strip())

def read(): return list(map(int, input().strip().split()))
def readf():return list(map(int, file.readline().strip().split()))



def factos(n, mod):
    arr = [0]*(n+1)
    a = 1
    for i in range(1, n+1):
        a *= i
        a%= mod
        arr[i] = a
    return(arr)

# file = open("input.txt", "r")
def solve():
    fact = factos(10**6, MOD)
    for _ in range(1):
        n = nin()
        ans_.append((fact[n] - pow(2,n-1,MOD))%MOD)
        
        
# file.close()
solve()

for i in ans_:print(i)
    