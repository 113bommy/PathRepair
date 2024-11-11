n,m,k=map(int,input().split())
if k<=n-1:
    print(1+k,"1")
else:
    k-=n
    if k//(m-1)==0:
        k+=1
        print(n,1+k)
    else:
        c=1
        a=k//(m-1)
        x=n-a
        if a%2==1:
            y=m-k%(m-1)
        else:
            y=2+k%(m-1)
        print(x,y)