a,b =map(int,input().split())
k = a%3
s = b%3
if k == s and k != 0:
  print("Impossible")
else:
  print("Possible")
