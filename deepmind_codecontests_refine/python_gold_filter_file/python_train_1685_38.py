t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr = [(arr[i], i) for i in range(n)]
    arr.sort()
    r1 = 0
    r = arr[0][1]
    ans = 0
    for k in range(1, n):
        if arr[k][0] != arr[k - 1][0]:
            r1 = r
        if arr[k][1] < r1:
            ans += 1
        elif arr[k][1] > r:
            r = arr[k][1]
    print(ans)