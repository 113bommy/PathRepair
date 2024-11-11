import math
import re
import sys
from collections import defaultdict
from heapq import heappush, heappop
from fractions import gcd

def read(type = int):
  return type(input())
  
def read_list(type = int, split = ' ', F = None):
  if F:
    return map(lambda x: F(type(x)), raw_input().split(split))
  return map(type, input().split(split))

def read_list_of_list(N, type = int, split = ' ', F = None):
  return [read_list(type, F = F) for _ in range(N)]


def solve():
  a,b,m = read_list()
  if a==b:
    return "1 %d" %a
  e = 0
  while a*2**e+m*2**e<b:
    e += 1
  if a*2**e>=b:
    return -1
  z = b-a*2**e-2**e
  if z<0:
    return -1
  X = [1]*(e+1)
  i = 0
  while z:
    if e > 0:
      e -= 1
    k = min(z//2**e, m-1)
    X[i] += k
    i += 1
    z -= k*2**e
#  print(X,z)
  R = [a]
  i = 0
#  X += [0]*3
#  print(X)
  while a<b:
    a = sum(R)+X[i]
    R += [a]
    i += 1
  return " ".join(map(str, [len(R)]+R))
      
q = read()
for _ in range(q):
  print(solve())
  
