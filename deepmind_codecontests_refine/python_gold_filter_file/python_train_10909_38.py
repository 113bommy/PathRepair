n = int(input())
luk = input()

keys = [str(i)+str(j)+str(k) for i in range(10) for j in range(10) for k in range(10)]
a = 0
for key in keys:
  s = 0
  for st in luk:
    if st == key[s]:
      s += 1
    if s == 3:
      a += 1
      s = 0
      break
print(a)