def getinput():
    return [int(x) for x in input().strip().split()]

t = int(input())

for t1 in range(t):
    n, k=getinput()
    arr=getinput()
    ans=max(arr[0], n-arr[-1]+1)
    # print (ans)
    for i in range(1, k):
        ans=max(ans, (arr[i]-arr[i-1]+2)//2)
    print (ans)