a,b,c,n = map(int,input().split())
if abs(a-c) <= n or (abs(a-b) <= n and abs(b-c) <= n):
  print("Yes")
else:
  print("No")