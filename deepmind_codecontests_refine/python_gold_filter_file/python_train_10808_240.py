a,b,c,d=map(int,input().split())

if abs(a-c) <=d or abs(c-b)<=d and abs(b-a)<=d:
  print("Yes")
else:
  print("No")