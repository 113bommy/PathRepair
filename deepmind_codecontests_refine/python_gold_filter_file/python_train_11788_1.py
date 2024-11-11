t = int(input())
for i in range(0, t):
  summa = 0
  s = input()
  s = s.strip("0")
  for c in s:
    if c == "0":
      summa = summa + 1
  print(summa)