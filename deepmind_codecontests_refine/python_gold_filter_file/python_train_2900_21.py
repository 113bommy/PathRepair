from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import *
from bisect import bisect
 
def read():
  return int(input())
 
def reads():
  return [int(x) for x in input().split()]

def f(*xs):
  return sum(x // 2 * 2 for x in xs)

def solve(I, J, L):
  ans = f(I, J, L)
  if min(I, J, L) >= 1:
    ans = max(ans, 3 + f(I-1, J-1, L-1))
  return ans

I, O, _, J, L, _, _ = reads()
ans = O + solve(I, J, L)
print(ans)