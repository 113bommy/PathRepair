def check(arr, n, h, k):
    for i in range(1, n):
        h -= min(arr[i]-arr[i-1], k)

    if h <= k:
        return True

    return False

t = int(input())
for _ in range(t):
    n,h = map(int, input().split())
    arr = list(map(int, input().split()))
    start = 1
    end = h

    while start <= end:
        mid = (start+end)//2
        
        if check(arr, n, h, mid):
            end = mid - 1
        
        else:
            start = mid + 1

    print(start)