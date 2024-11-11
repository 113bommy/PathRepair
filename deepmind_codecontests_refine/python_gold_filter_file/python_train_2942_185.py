t=int(input())

def f(num):
    s=1
    if num<7:
        for i in range(1,num):
            for j in range(1+i,num):
                if i+j==num:
                    s+=1
    elif num%2==0:
        s=num//2
    else:
        s=num//2+1
    return s;



for i in range(0,t):
    n=int(input())
    s=f(n)
    print(s)

