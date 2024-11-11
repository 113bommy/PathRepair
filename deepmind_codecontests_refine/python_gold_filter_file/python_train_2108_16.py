from sys import stdin
import math
a=int(stdin.readline())

for k in range(0,a):
    A=int(stdin.readline())
    A-=1

    if A==0:
        print(1)
        print(0)

    print(int(math.floor(math.log2(A+1))))
    temp=1
    layer=1
    while True:
        if A-2**temp<2**temp:
            B=int(math.floor(A/2))
            if B-2**(temp-1)>=0 and A-2**(temp-1)>layer:
               print(B-2**(temp-1),end=' ')
               print(A-2*B)
            else:
               print(A-2**(temp-1))
            break
        else:
            print(2**(temp-1),end=' ')
            A-=2**temp
            layer=2**temp
        temp+=1