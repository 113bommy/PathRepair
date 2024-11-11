
def Check(x) :
    if x * a >= k : return False
    xx = k - x * a
    yy = n - x
    if yy * b >= xx : return False
    return True

T = int(input())
while T > 0 :
    k, n, a, b = map(int,input().split())
    l = 0; r = n; ans = -1
    while l <= r :
        mid = (l + r) // 2
        if Check(mid) :
            l = mid + 1
            ans = mid
        else :
            r = mid - 1
    print(ans)
    T -= 1