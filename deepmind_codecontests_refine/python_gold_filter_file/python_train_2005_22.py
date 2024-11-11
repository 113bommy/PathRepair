import sys
from collections import deque
input = sys.stdin.readline
t = int(input())
for _ in range(t):
  n = int(input())
  a = deque(input().rstrip())
  b = input().rstrip()
  ans = []
  cnt = 0
  for i in range(1,n)[::-1]:
    if cnt%2 == 0:
      x = a.popleft()
    else:
      x = a.pop()
    if (cnt%2 == 0) ^ (x == b[i]) == 0:
      ans.extend((1,i+1))
    else:
      ans.append(i+1)
    cnt += 1
  if (cnt%2 == 0) ^ (a[0] == b[0]):
    ans.append(1)
  ansl = len(ans)
  print(ansl,*ans)