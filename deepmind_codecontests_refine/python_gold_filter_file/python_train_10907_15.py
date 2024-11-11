x,k,d = map(int, input().split())
x1=abs(x)
 
if x1>=k*d:
    print(x1-k*d)
else:
    if (k-x1//d)%2 == 0:
        print(x1%d)
    else:
        print(d-x1%d)