N, Q = map(int, input().split())
s = '#' + input() + '#'
T = []
D = []
for t, d in [input().split() for _ in range(Q)]:
  T.append(t)
  D.append(-1 if d=='L' else 1)

#そのゴーレムがどちらかの端にたどりつけるかの関数
def canReachEnd(iL, dir):
  nowL = iL
  nowt = s[iL]
  for t, d in zip(T, D):
    if t == nowt:
      nowL += d
      nowt = s[nowL]
  if dir == 1 and nowL == N+1:
    return True
  elif dir == -1 and nowL == 0:
    return True
  else:
    return False

#1. iは左にたどり着くがi+1は辿りつかないようなiを探す
left = 0
right = N+1
while right > left+1:
  check = (left+right)//2
  if canReachEnd(check, -1):
    left = check
  else:
    right = check
leftborder = left

#2. jは右にたどり着くがj-1は辿りつかないようなjを探す
left = leftborder
right = N+1
while right > left+1:
  check = (left+right)//2
  if canReachEnd(check, 1):
    right = check
  else:
    left = check
rightborder = right

dropcnt = 0
dropcnt += leftborder
dropcnt += (N-(rightborder-1))
print(N-dropcnt)
