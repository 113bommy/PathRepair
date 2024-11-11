import sys
from collections import Counter
N = int(input())
D = Counter([int(c) for c in input().split()])
M = int(input())
T = Counter([int(c) for c in input().split()])
for t in T.items():
  if D[t[0]] < t[1]:
    print('NO')
    sys.exit()
print('YES')