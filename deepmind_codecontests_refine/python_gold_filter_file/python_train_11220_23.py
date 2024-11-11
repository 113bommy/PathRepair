n,*a=map(int,open(0).read().split())
if 0 in a:
  print(0)
  exit()
s=1
for i in a:
  s*=i
  if s>10**18:
    print(-1)
    exit()
print(s)
