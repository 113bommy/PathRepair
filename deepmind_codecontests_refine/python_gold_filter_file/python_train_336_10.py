import sys
from collections import defaultdict
import heapq
input = sys.stdin.readline

MOD = int(1e9) + 7
    
def fast_pow(base, power, mod):
    if power == 1:
        return base
        
    val = fast_pow(base, power//2, mod)
    
    if power % 2 == 0:
        return val*val % mod
    
    if power % 2 == 1:
        return val*val*base % mod

def fact_by_mod(n, mod):
    ans = 1
    for i in range(2, n+1):
        ans *= i
        ans %= mod
    return ans
    
def solve(n):
    return (fact_by_mod(n, MOD) - fast_pow(2, n-1, MOD)) % MOD
        
    
    
    
    
if __name__ == "__main__":
    n = int(input())
    print(solve(n))
