k=int(input())
a,b=map(int,input().split())
if (a-1)//k<b//k:
  print("OK")
else:
  print("NG")