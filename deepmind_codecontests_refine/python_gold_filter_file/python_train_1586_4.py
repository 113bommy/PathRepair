for _ in range(int(input())):
    n,m = map(int,input().split())
    lis = list(map(int,input().split()))
    tem=lis[:]
    aa=[0]*102
    pos =list(map(int,input().split()))
    for i in pos:
        aa[i]=1
    i=0
    while i<101:
        if aa[i]==1:
            j=i+1
            while aa[j]==1:
                j+=1
            tem[i-1:j]=sorted(tem[i-1:j])
            i=j
        else:
            i+=1
    lis.sort()
    if lis==tem:
        print("YES")
    else:
        print("NO")        


