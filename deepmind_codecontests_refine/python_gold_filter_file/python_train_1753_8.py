k,a,b = map(int, input().split())
if k <= a:
  print(1)
elif b >= a:
  print(-1)
else:
  print(((k-a-1)//(a-b)+1)*2+1)
