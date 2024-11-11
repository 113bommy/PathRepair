n = int(input())
sm = 0
for i in range(1,n+1,1):
  if i%3 and i%5:
    sm+=i
print(sm)