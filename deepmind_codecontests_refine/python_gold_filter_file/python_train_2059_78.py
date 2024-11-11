A,Av= map(int, input().split())
B,Bv= map(int,input().split())
T = int(input())

if abs(B-A)>(Av-Bv)*T :
  print("NO")
else:
  print("YES")
  