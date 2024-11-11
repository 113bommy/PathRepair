import sys
import string

from collections import Counter, defaultdict
from math import fsum, sqrt, gcd, ceil, factorial
from itertools import combinations,permutations

# input = sys.stdin.readline
flush = lambda : sys.stdout.flush
comb = lambda x , y : (factorial(x) // factorial(y)) // factorial(x - y) 


#inputs
# ip = lambda : input().rstrip()
ip = lambda : input()
ii = lambda : int(input())
r = lambda : map(int, input().split())
rr = lambda : list(r())


n = ii()
arr = rr()
a = [False] * (n + 2)
# a[0] = a[1] = True


if n == 1:
    exit(print(1))

for i in range(2,n):
    if arr[i] == arr[i-1] + arr[i-2]:
        a[i] = True
      
  
ans = curr = 0
for i in a:
    if not i:
        ans = max(curr , ans)
        curr = 0
    else:
        curr += 1
print(ans + 2)