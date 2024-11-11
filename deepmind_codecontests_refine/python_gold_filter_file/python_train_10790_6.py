a,b,c = map(int,input().split())

if a == b:
    print(a+b+c//2*2)
else:
    dif= abs(a-b)
    if abs(dif)>=c:
        print((min(a,b)+c)*2)
    else:

        print(a+abs(dif)+b+((c-dif)//2*2))