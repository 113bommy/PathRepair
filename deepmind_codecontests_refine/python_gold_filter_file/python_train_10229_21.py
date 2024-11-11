t = int(input())

for i in range(t):
  counter = 0
  m = -1
  a, b, n = map(int, input().split())

  while m <= n:
    if a >= b:
      b += a
    else:
      a += b
    m = max([a,b])
    counter+=1
  print(counter)