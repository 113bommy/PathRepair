import sys
import math
from collections import defaultdict
from collections import deque
from itertools import combinations
from itertools import permutations
input = lambda : sys.stdin.readline().rstrip()
read = lambda : map(int, input().split())
def write(*args, sep="\n"):
  for i in args:
    sys.stdout.write("{}{}".format(i, sep))
INF = float('inf')
MOD = int(1e9 + 7)

n = int(input())
arr = list(read())
dp = [arr[0]]
flag = True 

for i in range(1, n):
  dp.append(dp[-1] + arr[i])

if len(list(filter(lambda x : x < 0, dp))) >= 1 or dp[-1] != 0:
  print("-1")
  exit()

prev = -1 
can = []
for i in range(n):
  if dp[i] == 0:
    can.append((prev + 1, i))
    prev = i 

for l, r in can:
  d = defaultdict(bool)
  for i in range(l, r+1):
    if arr[i] in d:
      print("-1")
      exit()
    if arr[i] < 0 and not -arr[i] in d:
      print("-1")
      exit()
    d[arr[i]] = True 

print(len(can))
for i, j in can:
  print(j - i + 1, end = " ")
    