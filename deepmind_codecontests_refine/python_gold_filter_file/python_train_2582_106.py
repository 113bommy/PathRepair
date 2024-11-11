A, B, C = map(int, input().split())
if (A - C) * (C - B) >= 0:
  print("Yes")
else:
  print("No")