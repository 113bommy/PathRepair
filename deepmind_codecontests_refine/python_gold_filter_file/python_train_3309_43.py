S, T = input().split()
A, B = map(int, input().split())
u = input()
if S==u:
  print(A-1, B)
else:
  print(A, B-1)