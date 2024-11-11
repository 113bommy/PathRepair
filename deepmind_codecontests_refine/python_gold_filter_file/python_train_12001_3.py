import math

ts=int(input())
for t in range(ts):
    n,k=input().split()
    n,k=int(n),int(k)
    arr=[]
    arr=input().split()
    for i in range(n):
        arr[i]=int(arr[i])
    arr.sort()
    ans=0
    for i in range(n):
        if(i==0):
            continue
        ans+=int((k-arr[i])/arr[0])
    print(math.floor(ans))
