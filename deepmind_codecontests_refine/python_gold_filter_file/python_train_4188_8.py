m = int(input())
for g in range(m):
    n = int(input())
    now = 0
    res = -99999999999
    was = False
    arr = list(map(int, input().split()))
    sm = sum(arr)
    for i in range(n):
        if arr[i] < 0:
            now += arr[i]
            if now < 0:
                now = 0
        else:
            now += arr[i]
        if now >= sm and i != n - 1:
            was = True
            break
    now = 0
    for i in range(n - 1, -1, -1):
        if arr[i] < 0:
            now += arr[i]
            if now < 0:
                now = 0
        else:
            now += arr[i]
        if now >= sm and i != 0:
            was = True
            break
    if was:
        print('NO')
    else:
        print('YES')
