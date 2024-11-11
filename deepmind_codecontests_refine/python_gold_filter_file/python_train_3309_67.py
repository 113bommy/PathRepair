s,t = input().split()
a,b = map(int,input().split())
k = input()
if k == s:
  print(a-1,b)
else:
  print(a,b-1)