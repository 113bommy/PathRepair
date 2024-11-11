x = int(input())
n = x//100
x -= n*100
if 5*n >= x:
  print("1")
else:
  print("0")