s = list(input())
if "L" in s[0::2] or "R" in s[1::2]:
  print("No")
else:
  print("Yes")