x = int(input())
a = 100
y = 0

while a < x:
  a += a//100
  y += 1

print(y)