s = input().rstrip()
n = len(s)
if n % 2 == 1:
  print("No")
  exit()
for a, b in zip(s[:n//2], s[::-1]):
  if a == "p" and b == "q":
    continue
  elif a == "q" and b == "p":
    continue
  elif a == "b" and b == "d":
    continue
  elif a == "d" and b == "b":
    continue
  else:
    print("No")
    exit()
print("Yes")