from math import ceil   
n=int(input())
if n<=9:
    print(n)
else:
    d=2
    ov=9
    while n>d*9*(10**(d-1))+ov:
        ov=d*9*(10**(d-1))+ov
        d+=1
    v=ceil((n-ov)/d)+int('9'*(d-1))
    print(str(v)[(n-ov-1)%d])