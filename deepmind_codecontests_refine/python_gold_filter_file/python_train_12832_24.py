import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
R = lambda : map(int, input().split())
for _ in range(int(input())) :
    n = int(input())
    a = list(R())
    a.sort()
    ans = 0
    for i in range(1, a[-1] + a[-1] + 1) :
        cnt = 0
        l, r = 0, n - 1
        while r > l :
            if a[l] + a[r] == i :
                cnt += 1
                l += 1
                r -= 1
            elif a[l] + a[r] < i :
                l += 1
            else :
                r -= 1
        ans = max(ans, cnt)
    print(ans)

