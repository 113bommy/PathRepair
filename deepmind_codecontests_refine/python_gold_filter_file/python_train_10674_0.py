n=int(input())
v=n%7
if v==0:
    print((n//7)*2,(n//7)*2)
elif v==1:
    print((n//7)*2,(n//7)*2+1)
elif v==6:
    print((n//7)*2+1,(n//7)*2+2)
else:
    print((n//7)*2,(n//7)*2+2)
