n = int(input())
s = list(input())
total = 0
for i in range(1000):
  t = list(str(i).zfill(3))
  j = 0
  for c in range(len(s)):
    if (j<=len(t)-1):
      if(s[c] == t[j]):
        j += 1
  if (j == 3):
    total += 1
print(total)