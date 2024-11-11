input();l=input().split();x=1
for j in sorted(l):
  x*=int(j)
  if x>1e18:x=-1;break
print(x)