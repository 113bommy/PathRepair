A,V = map(int,input().split())
B,W = map(int,input().split())
T = int(input())
if abs(B-A)+(W-V)*T > 0:
  print("NO")
else:
  print("YES")
