# -*- coding: utf-8 -*-

#############
# Libraries #
#############

import sys
input = sys.stdin.readline

import math
#from math import gcd
import bisect
import heapq
from collections import defaultdict
from collections import deque
from collections import Counter
from functools import lru_cache

#############
# Constants #
#############

MOD = 10**9+7
INF = float('inf')
AZ = "abcdefghijklmnopqrstuvwxyz"

#############
# Functions #
#############

######INPUT######
def I(): return int(input().strip())
def S(): return input().strip()
def IL(): return list(map(int,input().split()))
def SL(): return list(map(str,input().split()))
def ILs(n): return list(int(input()) for _ in range(n))
def SLs(n): return list(input().strip() for _ in range(n))
def ILL(n): return [list(map(int, input().split())) for _ in range(n)]
def SLL(n): return [list(map(str, input().split())) for _ in range(n)]

#############
# Main Code #
#############

N,K = IL()
data = SLL(N)
base = 10**6

BW_data = [[0 for i in range(2*K)] for i in range(2*K)]

for x,y,c in data:
  x,y = int(x)%(2*K),int(y)%(2*K)
  if c == "B":
    BW_data[y][x] += 1
  else:
    BW_data[y][x] += base

def ACC2(l):
  H = len(l)
  W = len(l[0])
  ret = [[0]*(W+1) for i in range(H+1)]
  for i in range(H):
    for j in range(W):
      ret[i+1][j+1] = ret[i+1][j] + ret[i][j+1] - ret[i][j] + l[i][j]
  return ret

def RANGE_SUM_in_ACC(l,h1,h2,w1,w2):
  return l[h2][w2]-l[h2][w1]-l[h1][w2]+l[h1][w1]

BW_ACC = ACC2(BW_data)

BW_res = [[0 for i in range(2*K)] for i in range(K)]

for j in range(K):
  for i in range(2*K):
    if i<K:
      BW_res[j][i] += RANGE_SUM_in_ACC(BW_ACC,j,j+K,i,i+K)
      BW_res[j][i] += RANGE_SUM_in_ACC(BW_ACC,0,max(0,j),0,max(0,i))
      BW_res[j][i] += RANGE_SUM_in_ACC(BW_ACC,0,max(0,j),min(2*K,i+K),2*K)
      BW_res[j][i] += RANGE_SUM_in_ACC(BW_ACC,min(2*K,j+K),2*K,0,max(0,i))
      BW_res[j][i] += RANGE_SUM_in_ACC(BW_ACC,min(2*K,j+K),2*K,min(2*K,i+K),2*K)
    else:
      BW_res[j][i] = BW_ACC[-1][-1]-BW_res[j][i-K]
      
ans = 0
for j in range(K):
  for i in range(2*K):
    ans = max(ans,BW_res[j][i]%base+BW_res[j][(i+K)%(2*K)]//base)
print(ans)