n, k = map(int, input().split())
if k * 3 > n:
    print(-1)
else:
    ans = []
    for i in range(1, k * 2 + 1):
        ans.append(k if i % k == 0 else i % k)
    if k % 2:
        ans.append(k)
        for i in range(k - 1, 0, -1):
            if i % 2:
                ans.append(ans[-1] + i)
            else:
                ans.append(ans[-1] - i)
    else:
        ans.extend([i for i in range(k, 0, -1)])
    ans.extend([(k - (i % k)) for i in range(k * 3 + 1, n + 1)])
    print(*ans)
