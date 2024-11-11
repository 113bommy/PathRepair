n = int(input())
ab,xa,bx,bxa = 0,0,0,0
for i in range(n):
  s = input()
  if s[-1] == 'A' and s[0] == 'B':
    bxa += 1
  if s[-1] == 'A':
    xa += 1
  if s[0] == 'B':
    bx += 1
  for j in range(len(s)-1):
    if s[j]+s[j+1] == 'AB':
      ab += 1
if bxa == xa == bx:
  print(ab+bxa-bool(bxa))
else:
  print(ab+min(xa,bx))