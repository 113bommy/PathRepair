n, m = map(int, input().split())
k=n*m+1
if n==1 or m==1:
  print(1)
  exit() 
else:
  print((k)//2)

