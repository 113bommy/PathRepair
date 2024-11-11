a,b,k = map(int,input().split())
l = range(a,b+1)
new = set(l[:k])|set(l[-k:])
 
for i in sorted(new):
  print(i)
