for _ in range(int(input())):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    arr.append(0)
    val=0
    flag=True;mmin=0
    if n==1:
        print(arr[0])
    else:
        for i in range(0,n):
            if flag:
                if arr[i]>arr[i+1]:
                    val+=arr[i]
                    flag=False
            else:
                if arr[i]<arr[i+1]:
                    val-=arr[i]
                    mmin=arr[i]
                    flag=True
        if flag==True:
            val+=mmin
        print(val)