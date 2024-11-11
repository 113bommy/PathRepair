a=[int(i) for i in input().split()]
b=sum(a)
if b%5==0 and b>0:
    print (int(b/5))
else:
    print(-1)
