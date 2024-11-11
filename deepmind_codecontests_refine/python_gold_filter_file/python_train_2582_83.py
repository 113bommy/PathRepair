a, b, c = map(int, input().split())
if (b-c)* (a-c) < 0:
  print("Yes")
else:
  print("No")