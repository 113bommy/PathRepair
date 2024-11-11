t1, t2 = map(int, input().split())
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

if ((a1 - b1) * (a2 - b2) > 0) or (abs(a1 - b1) * t1 > abs(a2 - b2) * t2):
  print(0)
elif abs(a1 - b1) * t1 == abs(a2 - b2) * t2:
  print("infinity")
else:
  d, m = divmod(abs(a1 - b1) * t1, abs(a2 - b2) * t2 - abs(a1 - b1) * t1)
  ans = d * 2
  if m > 0:
    ans += 1
  print(ans)
