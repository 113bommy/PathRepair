a, b = list(map(int,input().strip().split(' ')))
while True:
  if a == 0 or b == 0:
    break
  else:
    if a >= 2 * b:
      a %= 2 * b
    else:
      if b >= 2 * a:
        b %= 2 * a
      else:
        break
print(a,b)