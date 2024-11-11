A,B = map(int,input().split())
s = B%A
if s ==0:
  print(A+B)
else:
  print(B-A)