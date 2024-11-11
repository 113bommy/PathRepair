input()
p = list(map(int, input().split()))
a = 0
for i, p_ in enumerate(p):
  a += (p_ != (i + 1))
print('YNEOS'[a > 2 :: 2])
