A, B, C, X, Y = map(int,input().split())

if X>Y:
  print(min(A*X+B*Y, A*(X-Y)+C*Y*2, C*X*2))
if Y>=X:
  print(min(A*X+B*Y, B*(Y-X)+C*X*2, C*Y*2))