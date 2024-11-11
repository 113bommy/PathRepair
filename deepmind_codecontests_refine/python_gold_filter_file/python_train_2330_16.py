def solution():
    n,t = map(int,input().strip().split())
    a = list(map(int,input().strip().split()))
    res = -1
    l = 0
    sum = 0
    for r in range(n):
        sum += a[r]
        while sum > t:
            sum -= a[l]
            l += 1
        if res < r - l + 1:
            res = r -l + 1
    print(res)
solution()
