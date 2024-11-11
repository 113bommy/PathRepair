n = int(input())
s,i = 0,10
if n%2:
  print(0)
else:
  while i<=n:
    s += (n//i)
    i *= 5

  print(s)