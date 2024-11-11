A, B, C, D = map(int, input().split())
if ((C+B-1)//B) > ((A+D-1)//D):
  print("No")
else:
  print("Yes")