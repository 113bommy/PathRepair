from sys import *
from sys import stdin,stdout
from collections import Counter

int_arr = lambda : list(map(int,stdin.readline().strip().split()))
str_arr = lambda :list(map(str,stdin.readline().split()))
get_str = lambda : map(str,stdin.readline().strip().split())
get_int = lambda: map(int,stdin.readline().strip().split())
get_float = lambda : map(float,stdin.readline().strip().split())


mod = 1000000007
setrecursionlimit(1000)

def countPrimes(n):
    sieve = [True] * n
    sieve[0] = False
    sieve[1] = False
    for i in range(2,n):
        if sieve[i]:
            for j in range(i*i,n,i):
                sieve[j] = False
    return sieve 
        
lst = countPrimes(10**6)    

def ans(n,arr):
    dic = {}
    for ele,ct in Counter(arr).items():
        dic[ele] = ct

    if 1 not in dic or 2 not in dic:
        if 1 not in dic:
            lst = [2] * dic[2]
        else:
            lst = [1] * dic[1]
    else:
        lst = [2,1] + [2] * (dic[2] - 1) + [1] * (dic[1] -1)
    print(*lst) 





    



#for _ in range(int(input())):
n = int(input())
arr = int_arr()
ans(n,arr)
