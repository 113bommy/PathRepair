def solve(arr,n):
    if(n==1):
        return 1
    if(n==2):
        if(arr[1]>arr[0]):
            return 2
        else:
            return 1
    dp=list()
    org=list()
    curr=1
    org.append(1)
    for i in range(1,n):
        if(arr[i]>arr[i-1]):
            curr+=1
            org.append(curr)
        else:
            curr=1
            org.append(curr)
    dp.append(org[0])
    dp.append(org[1])
    for i in range(2,n):
        if(arr[i]>arr[i-2]):
            if(arr[i]>arr[i-1]):
                dp.append(max(dp[i-1]+1,org[i-2]+1))
            else:
                dp.append(max(org[i],org[i-2]+1))
            
        else:
            if(arr[i]>arr[i-1]):
                dp.append(dp[i-1]+1)
            else:
                dp.append(org[i])
    #print(dp)
    return max(dp)


n=int(input())
arr=list(map(int,input().split()))
print(solve(arr,n))