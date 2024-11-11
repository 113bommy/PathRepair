k=int(input())
a,b=map(int,input().split())

c=b//k

if a<=c*k:
  print("OK")
else:
  print("NG")