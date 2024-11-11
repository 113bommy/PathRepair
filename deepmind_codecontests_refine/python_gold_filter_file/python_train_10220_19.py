for _ in range(int(input())):
  n,k=map(int,input().split())
  a=list(map(int,input().split()))
  l=min(a)+k;h=max(a)-k
  if h>l:l=-1
  print(l)
