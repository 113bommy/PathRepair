n,x=map(int,input().split())
c=0
while(n):
    s=input().split()
    a=s[0]
    b=int(s[1])
    if a=="+":
        x=x+b
    else:
        if (x-b)>=0:
            x=x-b
        else:
            c=c+1
    n=n-1
print(x,c)    