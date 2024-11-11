for _ in " "*int(input()):
    a=int(input())
    b=list(map(int,input().split()))
    z=[0]*(a+1);k=[0]*a
    pre=0;j=1
    for i in range(a):
        if z[b[i]]==0:z[b[i]]=1;k[i]=b[i]
        else:
            while z[j]:j+=1
            k[i]=j;z[j]=1
            if k[i]>b[i]:k=[-1];break
        pre=b[i]
    print(*k)