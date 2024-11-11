for x in range(int(input())):
    a = list(map(int, input().split()))
    n = a[0]
    k = a[-1]
    b = list(map(int, input().split()))
    m = min(b) + k
    ans = 0
    for x in b:
        if x > m and ans != 1:
            if x - k > m:
                ans = 1
    if ans == 0:
        print(m)
    else:
        print(-1)