import sys
import math
from heapq import *;
input = sys.stdin.readline
from functools import cmp_to_key;

def pi():
    return(int(input()))
def pl():
    return(int(input(), 16))
def ti():
    return(list(map(int,input().split())))
def ts():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
mod = 1000000007;
f = [];
def fact(n,m):
    global f;
    f = [1 for i in range(n+1)];
    f[0] = 1;
    for i in range(1,n+1):
        f[i] = (f[i-1]*i)%m;

def fast_mod_exp(a,b,m):
    res = 1;
    while b > 0:
        if b & 1:
            res = (res*a)%m;
        a = (a*a)%m;
        b = b >> 1;
    return res;

def inverseMod(n,m):
    return fast_mod_exp(n,m-2,m);

def ncr(n,r,m):
    if n < 0 or r < 0 or r > n: return 0;
    if r == 0: return 1;
    return ((f[n]*inverseMod(f[n-r],m))%m*inverseMod(f[r],m))%m;

def main():
    B();

def B():
    n = pi();
    mp = {};
    for i in range(n):
        [name,score] = input().split(' ');
        score = int(score[:-1]);
        if name not in mp:
            mp[name] = score;
        else:
            val = mp[name]; 
            mp[name] = max(val,score);

    tot = 0;
    for item in mp:
        tot += 1;
    ans = {};
    for name in mp:
        count = 0;
        for other in mp:
            if name != other:
                if mp[other] > mp[name]:
                    count += 1;
        ans[name] = ((tot-count)/tot)*100;

    print(tot);
    for name in ans:
        print(name, "noob" if ans[name] < 50 else "random" if ans[name] < 80 else "average" if ans[name] < 90 else "hardcore" if ans[name] < 99 else "pro");
    

                

        


main();