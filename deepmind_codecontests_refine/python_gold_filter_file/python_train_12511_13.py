n,m=list(map(int,input().split()))
for i in range(1,n+1):
    j=i*(i+1)//2
#     print(j)
    if j>=m:
        if j==m and i==n:
            print(0)
            break
        else:
            t=n-i
            if j-t==m:
                print(t)
                break
            elif j-t<m:
                
                continue
                
            