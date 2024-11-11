input();l=input().split();x=not"0"in l
for j in l:x=x*int(j)if 0<=x*int(j)<=1e18else-1
print(x)