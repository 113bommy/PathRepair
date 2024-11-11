input()
def f(a):
  a = int(a)
  r = 0
  while a % 2 == 0:
    a /= 2
    r += 1
  return r
print(sum(map(f, input().split())))
