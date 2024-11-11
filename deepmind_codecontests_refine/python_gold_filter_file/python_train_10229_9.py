t=int(input())
for i in range(t):
    a,b,c=map(int,input().split())
    te=a+b
    a=max(a,b)
    b=te
    an=1
    #print(a,b)
    while a<=c and b<=c:
        te=a+b
        a=b
        b=te
        an=an+1
        #print(a,b)
        #print(a,b)
    print(an)
            
