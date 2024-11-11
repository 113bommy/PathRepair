t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    l = 0
    r = n-1
    b = []
    while l<r:
        b.append(a[l])
        b.append(a[r])
        l += 1
        r -= 1
    if l==r:
        b.append(a[l])
    print(*b[::-1])
