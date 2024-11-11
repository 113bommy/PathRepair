t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    if a==0 or b==0:
        print(0)
    elif a==1 and b==1:
        print(0)
    else:
        x=min(a,b)
        y=max(a,b)
        if y>=x*2:
            print(x)
        else:
            print((a+b)//3)