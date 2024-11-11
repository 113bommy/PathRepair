n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
f=0
if m>1:
    print('Yes')
else:
    for i in range(n):
        if a[i]==0:
            a[i]=b[0]
    for i in range(1,n):
        if a[i]<a[i-1]:
            f=1
            break
    if f==1:
        print('Yes')
    else:
        print('No')                

