n,k=map(int,input().split(" "))
a=list(map(int,input().split()))
arr=[-1]
for i in range(n):
    if a[i]==0:
        arr.append(i)

arr.append(n)
if len(arr)-2<=k:
    ans=[1]*n
    print(n)
    print(*ans)
else:
    x=len(arr)
    ans=0
    start=0
    end=-1
    #print(x,arr)
    for i in range(k+1,x):
        if ans<arr[i]-arr[i-k-1]-1:
            start=arr[i-k-1]+1
            end=arr[i]-1
            ans=arr[i]-arr[i-k-1]-1
        
    for i in range(start,end+1):
        a[i]=1
    
    print(ans)
    print(*a)
        