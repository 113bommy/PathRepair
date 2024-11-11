def fun(a):
    m1=int(a/4)
    m2=int(a%4)
    n1=int(a/7)
    n2=int(a%7)
    f1=int(n2%4)
    f2=int(n2/4)
    if(a<4):
        print('-1')
        return 0
    if(f1!=0):
        if(n1>=f1):
            f2+=(7*f1+f1)/4
            n1-=f1
        else:
            print('-1')
            return 0
        
    
    for i in range(0,int(f2),1):
        print(4,end='')
    for i in range(0,int(n1),1):
        print(7,end='')

t=int(input())
fun(t)
