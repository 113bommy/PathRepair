t1,t2 = map(int,input().split())
a1,a2 = map(int,input().split())
b1,b2 = map(int,input().split())
if a1*t1+a2*t2>=b1*t1+b2*t2:
    a1,a2,b1,b2 = b1,b2,a1,a2
d = b1*t1+b2*t2 - (a1*t1+a2*t2)
if d == 0:
    print('infinity')

elif a1*t1<b1*t1:
    print(0)
else:
    if (a1*t1 - b1*t1)*2%d ==0:
        print(((a1*t1 - b1*t1)*2+d-1)//d)
    else:
        print((a1*t1 - b1*t1)//d*2+1)
