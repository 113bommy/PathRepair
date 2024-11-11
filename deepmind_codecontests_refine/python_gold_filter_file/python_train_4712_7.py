for _ in range(int(input())):
    n,x=map(int,input().split())
    arr=list(map(int,input().split()))
    arr=sorted(arr,reverse=True)
    arr.insert(0,-1)

    temp=0
    count=0
    for i in range(1,n+1):
        if(arr[i]*(i-temp)>=x):
            count+=1
            temp=i
            # print(temp)
    print(count)