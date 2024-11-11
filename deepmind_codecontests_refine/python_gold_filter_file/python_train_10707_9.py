input()
a = list(map(int, input().split()))
c = {}
lb = lc = 0
for i in a:
  try:
    c[i] += 1
    lb += 1
  except:
    c[i] = 1
    lc += 1
print(lc if lb % 2 == 0 else lc-1)