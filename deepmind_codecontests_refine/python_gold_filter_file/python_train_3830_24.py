import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a, b, c = 0, 0, 0
L, R = [], []
for p in map(int, input().split()):
  if p < 0:
    a += 1
    L.append(p)
  elif p == 0:
    b += 1
  else:
    c += 1
    R.append(p)
L.sort()
R.sort()
s = a*c
t = b*(b-1)//2 + (a+c)*b
if s < k <= s+t:
  ans = 0
else:
  if k <= s:
    ok = -1
    ng = -(10**18+1)
    while ok - ng > 1:
      mid = (ok+ng)//2
      now = 0
      temp = 0
      for l in L:
        while now < c and l*R[now] > mid:
          now += 1
        temp += c - now
      if temp >= k:
        ok = mid
      else:
        ng = mid
  else:
    ok = 10**18
    ng = 0
    while ok - ng > 1:
      mid = (ok+ng)//2
      now = c - 1
      temp = s+t
      for i, r in enumerate(R):
        if now <= i:
          break
        while now > i and r*R[now] > mid:
          now -= 1
        temp += now - i
      now = 0
      for i in range(a-1, -1, -1):
        l = L[i]
        if now >= i:
          break
        while now < i and l*L[now] > mid:
          now += 1
        temp += i - now
      if temp >= k:
        ok = mid
      else:
        ng = mid
  ans = ok
print(ans)