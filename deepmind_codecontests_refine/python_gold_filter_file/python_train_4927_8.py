for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    for i in range(n):
        arr[i]=[arr[i],i+1]
    arr.sort()
    ans = 0
    for i in range(n):
        k = arr[i][0]
        j = i+1
        while(j<n and arr[j][0]<=(2*n)//k):
            if arr[j][0]*arr[i][0]==arr[i][1]+arr[j][1]:
                ans+=1
            j+=1
    print(ans)