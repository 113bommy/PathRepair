n=int(input())
for i in range(n):
    n=int(input())
    b=list(map(int,input().split()))
    c=dict()
    for j in range(n):
        c[b[j]]=j
    j=1
    q=n-1
    p=1
    f=0
    while(j<n):
        k=c[j]
        if k==q:
            q=c[p]-1
            p=j+1


        else:
            if c[j+1]-k==1:
                pass
            else:
                f=1
                break
        j+=1
    if f==1:
        print("No")
    else:
        print("Yes")












