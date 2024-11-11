a,b,k=map(int,input().split())
l=range(a,b+1)
la= set(l[:k]) | set(l[-k:])
for i in (sorted(la)):
  print(i)