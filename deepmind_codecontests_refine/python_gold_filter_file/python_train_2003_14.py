t = int(input())
for i in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    mx = -1e10
    big = 0
    for i in range(n):
        big = max(big, mx - a[i])
        mx = max(mx, a[i])
    if big == 0:
        print(0)
    else:
        left = 0
        right = 50
        while (right - left) > 1:
            mid = (left + right) // 2
            if pow(2, mid) - 1 < big:
                left = mid
            else:
                right = mid
        if pow(2, left) - 1 < big:
            print(right)
        else:
            print(left)