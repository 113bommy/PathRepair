n,p,w,d = map(int,input().split())
if p==0:
    print(0," ",0," ",n)
elif p<d or n*w<p or w>p and p//d>n or p%w!=0 and p%d!=0 and w%d==0:
    print(-1)
else:
    if p%w==0:
        x=p//w;
        y=0;
        z=n-x;
        print(x," ",y," ",z)
    else:
        x=p//w;
        y=(p-x*w)//d;
        z=n-x-y;
        if (p-x*w)%d==0:
            z=n-x-y
            print(x," ",y," ",z)
 
        else:
            while True:
                x-=1;
                y=(p-x*w)//d;
                z=n-x-y;
                if x*w+y*d==p:
                    print(x," ",y," ",z)
                    break