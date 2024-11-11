from math import factorial as F

def ncr(n, r):
    return F(n) // ( F(r) * F(n - r) )
    
n = int(input()) * 2 - 2

print(ncr(n, n // 2))