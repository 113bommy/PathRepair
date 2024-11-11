t=int(input())
while t>0:
    t-=1
    c,s=map(int,input().split())
    if c==1:
        print(s**2)
    elif s<c:
        print(s)
    elif s>=c:
        if s%c==0:
            z=int(s/c)
            print(c*(z**2))
        else:
            x=s%c
            y=int(s/c)
            sum=x*((y+1)**2)+(c-x)*(y**2)
            print(sum)


