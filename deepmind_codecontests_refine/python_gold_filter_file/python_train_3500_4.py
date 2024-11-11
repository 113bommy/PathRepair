n, k = map(int, input().split())

*a, = map(int, input().split())

ans = -1000000001

if k == 1:
    print(min(a))
elif k >= 3:
    print(max(a))
else:
    temp_min= 1000000001

    for i in range(n - 1):
        temp_min = min(temp_min, a[i])
        ans = max(temp_min, ans)
        
    temp_min = 1000000001
    for i in range(n - 1, 0, -1):
        temp_min = min(temp_min, a[i])
        ans = max(temp_min, ans)

    print(ans)
