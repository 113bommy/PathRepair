t=int(input())
for i in range(t):
    n,p,k=map(int,input().split())
    arr=list(map(int,input().split()))
    arr=sorted(arr)
    sume=[0 for i in range(n)]
    flag=0
    for j in range(n):
        if(j>1):
            sume[j]=arr[j]+sume[j-2]
        else:
            sume[j]=arr[j]
        if(sume[j]>p):
            flag=1
            break
    if(flag==1):
        print(j)
    else:
        print(j+1)