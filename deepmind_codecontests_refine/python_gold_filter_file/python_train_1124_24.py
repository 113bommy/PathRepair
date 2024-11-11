# /usr/bin/python
# -*- coding: utf-8 -*-
#
import sys


N,Q = map(int, sys.stdin.readline().rstrip().split())
s = [""] + list(str(input())) + [""]
td = [["" for j in range(2)] for i in range(Q)]
for i in range(Q):
  td[i] = list(map(str, sys.stdin.readline().rstrip().split()))


# idx の位置の文字が左に消えるなら "L",
# 右に消えるなら "R", そうでなければ "F"
def check(idx):
  for t,d in td:
    if s[idx] == t:
      if d == "L":
        idx -= 1
      else:
        idx += 1
    if idx == 0:
      return "L"
    elif idx == N+1:
      return "R"
  return "F"


if __name__ == "__main__":
  # L のポイントをbinary search
  l,r = [0,N+1]
  while(r-l > 1):
    mid = (r+l) // 2
    if check(mid) == "L":
      l = mid
    else:
      r = mid
  lp = l

  # R のポイントをbinary search
  l,r = [0,N+1]
  while(r-l > 1):
    mid = (r+l) // 2
    if check(mid) == "R":
      r = mid
    else:
      l = mid
  rp = r-1

  print(rp-lp)
