from sys import stdin
def read(): return map(int, stdin.readline().split())

read()
a = list(read())
x = min(a)
for y in a:
  if y % x != 0:
    x = -1
    break

print(x)
