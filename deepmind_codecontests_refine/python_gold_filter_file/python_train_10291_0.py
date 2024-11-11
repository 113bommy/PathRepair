L=[1,0,1,2,1,2,1,1,2,1,2,1]
a,b=map(int,input().split())
if L[a-1]==L[b-1]:
  print("Yes")
else:
  print("No")