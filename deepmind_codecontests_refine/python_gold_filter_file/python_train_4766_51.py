a,b = list(map(int,input().split()))
if a*2 <= b <= a*4 and b%2 == 0:
  print("Yes")
else:
  print("No")