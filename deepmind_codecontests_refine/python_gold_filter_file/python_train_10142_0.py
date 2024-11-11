a, b = map(int,input().split())

draw = 0
win = 0
lose = 0
for i in range(1,7):
  if abs(i-a) == abs(i -b) :
    draw+=1
  elif abs(i-a) < abs(i -b) :
    lose += 1
  else : 
    win += 1

print(lose, draw, win)