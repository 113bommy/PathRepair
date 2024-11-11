d=b=0;n=int(input());a=[int(x) for x in input().split()];
for i in range(n):
    if a[i]%2==0: d+=1
    else: b+=1
if sum(a)%2==0: print(d)
else: print(b)