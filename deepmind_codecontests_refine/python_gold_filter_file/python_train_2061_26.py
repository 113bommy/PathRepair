order = input()
if "R" in order[1::2] or "L" in order[::2]:
  print("No")
else:
  print("Yes")