import sys
import math
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
mod = 998244353;
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
    if r == 0: return 1;
    return ((f[n]*inverseMod(f[n-r],m))%m*inverseMod(f[r],m))%m;

def main():
    D();

def D():
    t = pi();
    while t:
        t -= 1;
        n = pi();
        h = [0 for i in range(n)];
        b = [0 for i in range(n)];
        for i in range(n):
            [x,y] = ti();
            h[i] = x;
            b[i] = y;
        inf = 999999999999999999999;
        dp = [[0 for j in range(n)] for i in range(3)];
        dp[0][0] = 0;
        dp[1][0] = b[0];
        dp[2][0] = 2*b[0];
        for i in range(1,n):
            if h[i] == h[i-1]:
                dp[0][i] = min(dp[1][i-1],dp[2][i-1]);
                dp[1][i] = b[i] + min(dp[0][i-1],dp[2][i-1]);
                dp[2][i] = 2*b[i] + min(dp[0][i-1],dp[1][i-1]);
            else:
                dp[0][i] = min(dp[0][i-1],dp[1][i-1] if 1+h[i-1] != h[i] else inf,dp[2][i-1] if 2+h[i-1] != h[i] else inf);
                dp[1][i] = b[i] + min(dp[0][i-1] if 1+h[i] != h[i-1] else inf,dp[1][i-1],dp[2][i-1] if 2+h[i-1] != 1+h[i] else inf);
                dp[2][i] = 2*b[i] + min(dp[0][i-1] if 2+h[i]!=h[i-1] else inf,dp[1][i-1] if 2+h[i]!=1+h[i-1] else inf,dp[2][i-1]);
        print(min(dp[0][n-1],dp[1][n-1],dp[2][n-1]))

main();