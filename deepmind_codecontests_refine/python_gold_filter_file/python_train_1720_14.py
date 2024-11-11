x=int(input())
lo = 0
hi = 1000000000
while lo < hi:
    mid = (lo + hi + 1) // 2
    if mid * (mid+1) // 2 >= x:
        hi = mid - 1
    else:
        lo = mid

print(x - lo*(lo+1)//2)