A,B,X = map(int,input().split())
s = "YES"
if A > X or A+B < X:
  s = "NO"
print(s)