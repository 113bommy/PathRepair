import sys
input = sys.stdin.readline
from collections import deque
t = int(input())
for _ in range(t):
  s = input().rstrip()
  n = len(s)
  ls = [0]*51
  ls[25] = s[0]
  st = set(s[0])
  flg = 1
  l = 25
  r = 25
  now = 25
  for i in range(1,n):
    if s[i] not in st:
      if ls[l] == s[i-1]:
        ls[l-1] = s[i]
        l -= 1
        now -= 1
      elif s[i-1] == ls[r]:
        ls[r+1] = s[i]
        r += 1
        now += 1
      else:
        print("NO")
        flg = 0
        break
      st.add(s[i])
    else:
      if ls[now-1] == s[i]:
        now -= 1
      elif ls[now+1] == s[i]:
        now += 1
      else:
        print("NO")
        flg = 0
        break
  if flg:
    print("YES")
    for i in range(l,r+1):
      print(ls[i],end="")
    for i in range(97,97+26):
      if chr(i) not in st:
        print(chr(i),end="")
    print("")