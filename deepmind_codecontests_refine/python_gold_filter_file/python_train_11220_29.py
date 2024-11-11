input()
l = list(map(int, input().split()))
l.sort()
r = 1
for i in l:
  r *= i
  if r > 10 ** 18:
    print('-1')
    exit(0)
print(r)