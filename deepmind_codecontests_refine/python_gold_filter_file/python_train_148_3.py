a=[int(x) for x in input().split()]
b=sum(a)
if b%5==0 and b>0:
    print(b//5)
else:
    print(-1)
