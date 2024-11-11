cases = int(input())

for i in range(cases):
  n,m,r_b,c_b,r_d,c_d = [int(x) for x in input().split()]
  x = 1
  y = 1
  count = 0
  while True:
    if (r_b == r_d) or (c_b == c_d):
      break
    if r_b == n and y == 1:
      y = -1
    if c_b == m and x == 1:
      x = -1
    if r_b == 1 and y == -1:
      y = 1
    if c_b == 1 and x == -1:
      x = 1

    r_b += y
    c_b += x
    count += 1
  print(count)