#F
t1,t2 = map(int,input().split())
a1,a2 = map(int,input().split())
b1,b2 = map(int,input().split())
l1 = (a1-b1)*t1
l2 = (a2-b2)*t2

    
if (l1+l2)==0:
    print('infinity')
elif (l1)*(l1+l2)>0:
    print(0)
else:
    zure = abs(l1+l2)
    oitsuki = abs(l1)
    n = oitsuki//zure
    if n * zure == oitsuki:
        print(2*n)
    else:
        print(2*n+1)