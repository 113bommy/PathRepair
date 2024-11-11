for _ in range(int(input())):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    if(n==1):
        print(sum(a))
    elif(n%2==0):
        d = n // 2 -1
        e = n - d
        f = 0
        sum1 = 0
        for i in range(len(a) - e, -1, -e):
            sum1 += a[i]
            f += 1
            if (f == k):
                break
        print(sum1)
    else:
        d=n//2
        e=n-d
        f=0
        sum1=0
        for i in range(len(a)-e,-1,-e):
            sum1+=a[i]
            f+=1
            if(f==k):
                break
        print(sum1)