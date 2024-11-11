A,B = map(int,input().split())
C = B%A
if (C == 0):
  print(A+B)
else:
  print(B-A)