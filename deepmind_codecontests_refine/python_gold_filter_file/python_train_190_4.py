s,t = 0,0
for x in input():
  if x == 'S':
    s += 1
  else:
    if s > 0:
      s -= 1
    else:
      t += 1

print(s+t)