t = int(input())
while t>0:
    n,m = map(int, input().split())
    a = list(map(int, input().split()))
    if m < n or n==2:
        print ('-1')
    else:
        arr = []
        s = 2*sum(a)
        for i in range(n):
            arr.append([a[i],i])
        arr = sorted(arr, key=lambda x:x[0])
        s+=(m-n) * (arr[0][0] + arr[1][0])
        print (s)
        for i in range(n):
            print (arr[i][1] + 1, arr[(i+1)%n][1] + 1)
        for i in range(n,m):
            print (arr[0][1] + 1, arr[1][1] + 1) 
    t-=1