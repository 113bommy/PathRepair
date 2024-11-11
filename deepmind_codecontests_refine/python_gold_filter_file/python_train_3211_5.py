N,Z,W=map(int,input().split())
a=[int(i) for i in input().split()]
if N==1:
  print(abs(W-a[0]))
else:
  print(max(abs(W-a[-1]),abs(a[-2]-a[-1])))