test=int(input())
while test>0:
    test=test-1
    n=int(input())
    a=list(map(int,input().split()))
    dif=0
    
    a.sort()   
    for i in range(n-1):
        if abs(a[i]-a[i+1])>1:
            dif=2
            break
            
    if dif==2:
        print('NO')
    else:
        print('YES')
            
            
    