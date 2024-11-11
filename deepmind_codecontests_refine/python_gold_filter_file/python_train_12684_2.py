import bisect
s = input()
n = len(s)
dp = [[0 for i in range(26)] for j in range(n+1)]
flg = [0]*26
prt = []
for i in range(n-1,-1,-1):
  x = ord(s[i])-97
  for j in range(26):
    if j == x:
      dp[i][j] = n-i
      flg[x] = 1
    else:
      dp[i][j] = dp[i+1][j]
  if flg.count(1) == 26:
    prt.append(i)
    flg = [0]*26
ind = 0
ans = []
if not prt:
  for i in range(26):
    if dp[0][i] == 0:
      print(chr(i+97))
      exit()
prt = prt[::-1]
for i in range(26):
  if dp[prt[0]][i] == dp[0][i]:
    ans.append(i)
    break
else:
  ans.append(0)

pnt = prt[0]
flg = 0
while True:
  c = ans[-1]
  if not flg:
    pnt = n-dp[pnt][c]
  flg = 0
  prtp = bisect.bisect_right(prt,pnt)
  if prtp == len(prt):
    for i in range(26):
      if dp[pnt+1][i] == dp[-1][i]:
        ans.append(i)
        break
    else:
      ans.append(0)
    for od in ans:
      print(chr(od+97),end="")
    break
  npnt = prt[prtp]
  for i in range(26):
    if dp[pnt+1][i] == dp[npnt][i]:
      ans.append(i)
      break
  else:
    ans.append(0)
    flg = 1
  pnt = npnt
