def main():
  a = [int(x) for x in input().split()]
  legtobb = 0
  b = 0
  c = 0
  sorozat = [int(x) for x in input().split()]
  helyek = []
  helyek.append(-1)
  for x in range(len(sorozat)):
    if sorozat[x] == 0:
      helyek.append(x)
  helyek.append(a[0])
  mo = [0,0]
  if a[1] >= len(helyek)-2:
    for x in range(len(sorozat)):
      sorozat[x] = 1
      c = a[0]
  else:
    for x in range(len(helyek)):
      if b + a[1] + 1 < len(helyek) and helyek[b+a[1] + 1] - helyek[b] - 1 > c:
        c = helyek[b+a[1] + 1] - helyek[b] - 1
        mo = [helyek[b], helyek[b+a[1] + 1]]
      b = b + 1
    for x in range(len(sorozat)):
      if mo[0] < x and x < mo[1]:
        sorozat[x] = 1
  print(c)
  for x in range(len(sorozat)):
    print(sorozat[x], end = " ")
main()