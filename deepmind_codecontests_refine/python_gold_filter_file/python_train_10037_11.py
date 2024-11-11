a = ""
for c in input():
  if len(a) > 2 and a[-3] == a[-2] and a[-1] == c or len(a) > 1 and a[-2] == a[-1] == c:
    continue
  a += c
print(a)