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


#####Shorten#####
def DD(arg): return defaultdict(arg)

#####Inverse#####
def inv(n): return pow(n, MOD-2, MOD)

######Combination######
kaijo_memo = []
def kaijo(n):
  if(len(kaijo_memo) > n): return kaijo_memo[n]
  if(len(kaijo_memo) == 0): kaijo_memo.append(1)
  while(len(kaijo_memo) <= n): kaijo_memo.append(kaijo_memo[-1] * len(kaijo_memo) % MOD)
  return kaijo_memo[n]

gyaku_kaijo_memo = []
def gyaku_kaijo(n):
  if(len(gyaku_kaijo_memo) > n): return gyaku_kaijo_memo[n]
  if(len(gyaku_kaijo_memo) == 0): gyaku_kaijo_memo.append(1)
  while(len(gyaku_kaijo_memo) <= n): gyaku_kaijo_memo.append(gyaku_kaijo_memo[-1] * pow(len(gyaku_kaijo_memo),MOD-2,MOD) % MOD)
  return gyaku_kaijo_memo[n]

def nCr(n,r):
  if n == r: return 1
  if n < r or r < 0: return 0
  ret = 1
  ret = ret * kaijo(n) % MOD
  ret = ret * gyaku_kaijo(r) % MOD
  ret = ret * gyaku_kaijo(n-r) % MOD
  return ret

######Factorization######
def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(-(-n**0.5//1))+1):
    if temp%i==0:
      cnt=0
      while temp%i==0: 
        cnt+=1 
        temp //= i
      arr.append([i, cnt])
  if temp!=1: arr.append([temp, 1])
  if arr==[]: arr.append([n, 1])
  return arr

#####MakeDivisors######
def make_divisors(n):
  divisors = []
  for i in range(1, int(n**0.5)+1):
    if n % i == 0:
      divisors.append(i)
      if i != n // i: 
        divisors.append(n//i)
  return divisors

#####MakePrimes######
def make_primes(N):
  max = int(math.sqrt(N))
  seachList = [i for i in range(2,N+1)]
  primeNum = []
  while seachList[0] <= max:
    primeNum.append(seachList[0])
    tmp = seachList[0]
    seachList = [i for i in seachList if i % tmp != 0]
  primeNum.extend(seachList)
  return primeNum

#####GCD#####
def gcd(a, b):
    while b: a, b = b, a % b
    return a

#####LCM#####
def lcm(a, b):
    return a * b // gcd (a, b)

#####BitCount#####
def count_bit(n):
  count = 0
  while n:
    n &= n-1
    count += 1
  return count

#####ChangeBase#####
def base_10_to_n(X, n):
  if X//n: return base_10_to_n(X//n, n)+[X%n]
  return [X%n]

def base_n_to_10(X, n):
  return sum(int(str(X)[-i-1])*n**i for i in range(len(str(X))))

def base_10_to_n_without_0(X, n):
  X -= 1
  if X//n: return base_10_to_n_without_0(X//n, n)+[X%n]
  return [X%n]

#####IntLog#####
def int_log(n, a):
  count = 0
  while n>=a:
    n //= a
    count += 1
  return count

#############
# Main Code #
#############


H,W = IL()
data = ILL(H)

class BIT:
  def __init__(self, logn):
    self.n = 1<<logn
    self.data = [0]*(self.n+1)
    self.el = [0]*(self.n+1)
  def sum(self, i):
    s = 0
    while i > 0:
      s += self.data[i]
      i -= i & -i
    return s
  def add(self, i, x):
    # assert i > 0
    self.el[i] += x
    while i <= self.n:
      self.data[i] += x
      i += i & -i
  def get(self, i, j=None):
    if j is None:
      return self.el[i]
    return self.sum(j) - self.sum(i)
  def bisect(self, x):
    w = i = 0
    k = self.n
    while k:
      if i+k <= self.n and w + self.data[i+k] < x:
        w += self.data[i+k]
        i += k
      k >>= 1
    return i+1


dic = DD(int)
for i in range(W):
  dic[i+1] = i+1

members = DD(int)
for i in range(W):
  members[i+1] = 1


B = BIT(int_log(W,2)+1)

for i in range(W):
  B.add(i+1,1)
  

def calc_prev_valid(x):
  s = B.sum(x-1)
  if s == 0:
    return 0
  else:
    return B.bisect(s)
    
#print(calc_prev_valid(0))
#exit()

count_score = DD(int)
count_score[0] = W
score = 0


for i in range(H):
  

  a,b = data[i]
  now = b
  while now >= a:
    if B.el[now]:
      #print("shorisita",now)
      count_score[now-dic[now]] -= members[now]
      if not B.el[b+1]:
        dic[b+1] = dic[now]
        B.add(b+1,1)
      if b+1 < W+1:
        #print((b+1),dic[b+1])
        count_score[(b+1)-dic[b+1]] += members[now]
      B.add(now,-1)
      members[b+1] += members[now]
      members[now] = 0

    now = calc_prev_valid(now)

  #print(dic)
  #print(members)
  #print(prev_valid)
  #print(count_score)
  while True:
    if count_score[score]:
      print(score+i+1)
      break
    else:
      score += 1
    if score == W:
      for _ in range(H-i):
        print(-1)
      exit()
