x=int(input())
for i in range(x):
    a,b=map(int,input().split())
    t1=abs(a-b)
    if(a>=b):
        t1=min(t1,(a+b)%2)
    print(t1)
    
