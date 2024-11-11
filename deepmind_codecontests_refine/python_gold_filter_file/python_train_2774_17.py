def solve():
    n,k = map(int,input().split())
    arr = list(map(int,input().split()))
    t1,val = -1,n+1
    v1 = 0
    for i in range(k):
        if n%arr[i]==0:
            print(i+1,' ',n//arr[i])
            return
        elif val> n%arr[i]:
            val = n%arr[i]
            v1 = n//arr[i]
            t1 = i+1
    print(t1,' ',v1)

solve()