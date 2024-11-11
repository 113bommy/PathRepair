input();l=input().split();x=not'0'in l
for j in l:
  x*=int(j);
  if x>1e18:x=-1;break
print(x)