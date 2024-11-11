x,y = map(int,input().split())
t = 0
while x <= y:
  x *= 2
  t += 1

print(t)