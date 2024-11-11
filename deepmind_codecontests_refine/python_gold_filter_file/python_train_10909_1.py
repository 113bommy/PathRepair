n = int(input())
s = input()
cou = 0
for i in range(1000):
  i = "{0:03d}".format(i)
  t = 0
  r = 0
  while r!=n:
    if s[r]==i[t]:
      t += 1
    if t==3:
      cou += 1
      r = n-1
    r += 1            
print(cou)
