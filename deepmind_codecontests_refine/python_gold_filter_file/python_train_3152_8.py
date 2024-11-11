t = int(input())
for _ in range(t):
    a,b,x,y,n = map(int,input().split())
    p = 100000000000000000000000
    #case1 
    if(a-n>=x):
        p = min(p, (a-n)*b)
    elif(a-n<x):
        if(b-(n-(a-x))>=y):
            p = min(p,x*(b-(n-(a-x))))
        else:
            p = min(p,x*y)
    #case2
    if(b-n>=y):
        p = min(p,(b-n)*a)
    elif(b-n<y):
        if(a-(n-(b-y))>=x):
            p = min(p,y*(a-(n-(b-y))))
        else:
            p = min(p,x*y)
    print(p)
        