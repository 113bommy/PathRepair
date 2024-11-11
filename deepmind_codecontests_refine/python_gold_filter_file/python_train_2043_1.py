def gbpx(i,j):
    global k
    if(k==1): return
    else:
        if(j-i==1): return
        else:
            k-=2
            mid=(i+j)//2
            a=s[mid-1]
            b=s[mid]
            s[mid-1]=b
            s[mid]=a
            gbpx(i,mid)
            gbpx(mid,j)
n,k=map(int,input().split())
s=[i for i in range(1,n+1)]
if(k%2==0 or k>n*2):print(-1)
else:
    gbpx(0,n)
    for i in range(0,n):
        print('%d ' %(s[i]),end='')