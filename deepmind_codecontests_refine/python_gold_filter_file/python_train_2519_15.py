T=int(input())
for _ in range(T):
    a,b,c,d=map(int,input().split())
    q=d//c
    if(q>a):
        d-=a*c
        if(d>b):
            print("No")
        else:
            print("Yes")
    elif(q<=a):
        d-=q*c
        if(d>b):
            print("No")
        else:
            print("Yes")
