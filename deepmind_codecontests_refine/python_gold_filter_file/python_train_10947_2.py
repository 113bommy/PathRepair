q=int(input())
a=[2,3,5]
for _ in range(q):
    n=int(input());N=n
    ans=0
    while N>1:
        ok=0;
        for x in a:
            if N%x==0:N//=x;N*=(x-1);ans+=1;ok=1;break;
        if ok==0:break;
    print([ans,-1][N>1])
