X,A,B = map(int, input().split())
if abs(A-X) < abs(B-X):
  print("A")
else:
  print("B")