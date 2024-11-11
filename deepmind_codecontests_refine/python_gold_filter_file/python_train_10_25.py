x = int(input())

for i in range(0, x):
  s = ''
  s1 = input().split()
  l = int(s1[0])
  r = int(s1[1])
  y = int(s1[2])
  if y < l:
    print(str(y))

  else:
    x = (-1 * r) % y
    if x == 0:
      x = y
    print(str(r + x))

