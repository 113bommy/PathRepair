n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
left = 0
right = 10**9+1
ans = (0, 0)
while left < right:
    mid = (left + right) // 2
    masks = {}
    for i in range(n):
        mask = 0
        for j in a[i]:
            mask <<= 1
            if j >= mid:
                mask += 1
        masks[mask] = i
    ok = False
    for m1 in masks:
        for m2 in masks:
            if m1 | m2 == ((1 << m) - 1):
                ok = True
                ans = (masks[m1]+1, masks[m2]+1)
                break
        if ok:
            break
    if ok:
        left = mid+1
    else:
        right = mid
print(ans[0], ans[1])
