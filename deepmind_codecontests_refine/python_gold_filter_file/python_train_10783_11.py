n, m = map(int, input().split())

l = 0
r = 10**18 + 1

def can(mid):
    if mid <= m:
        return (n - mid) > 0
    
    plus = (n - m) - ((mid-m) * (mid-m+1)) // 2
    return plus > 0

while r - l > 1:
    mid = (l + r) // 2
    if can(mid):
        l = mid
    else :
        r = mid

print(r);
