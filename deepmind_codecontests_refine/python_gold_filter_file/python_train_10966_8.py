n,k=map(int,input().split())
if k//n>2:
    print(0)
elif k/n==2:
    print(n)
elif k//n<2:
    print(n)
else:
    i=1
    r=0
    while(True):
        r+=2
        if (k-r)%3==0 and (k-r)/3==n-i:
            print(i)
            break
        if r>=k:
            print(i)
            break
        i+=1