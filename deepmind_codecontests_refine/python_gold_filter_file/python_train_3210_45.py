a,b,k=map(int,input().split())
c = range(a,b+1)
for i in sorted(set(c[:k])|set(c[-k:])):
  print(i)