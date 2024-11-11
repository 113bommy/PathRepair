A,B = map(int,input().split())

if B%A==0:
  print(int(A+B))
else:
  print(int(B-A))