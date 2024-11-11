for w in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    x=a[0]
    l=[0]*33
    m=-1
    for i in range(33):
        l[i]=pow(2,i)
    for i in range(1,n):
        if(a[i]>=a[i-1]):
            continue
        else:
            diff=a[i-1]-a[i]
            for j in range(33):
                if(l[j]>=diff):
                    a[i]=a[i-1]
                    if(l[j]==diff):
                       m=max(m,j)
                    else:
                        if(j>0):
                            m=max(m,j-1)
                        else:
                            m=max(m,j)
                    break
    print(m+1)