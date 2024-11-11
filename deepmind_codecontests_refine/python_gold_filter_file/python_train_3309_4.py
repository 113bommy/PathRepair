s,t = input().split()
A,B = map(int,input().split())
x = input()
if x == s:
  print(A-1, B)
else:
  print(A, B-1)