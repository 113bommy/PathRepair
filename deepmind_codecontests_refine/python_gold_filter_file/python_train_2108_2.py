def bin(n, s):
    l = 0
    r = n
    while l < r:
        mid = (l + r) // 2
        if 0 <= s - 2 * mid <= n + mid:
            return [mid, s - 2 * mid]
        if s - 2 * mid > n + mid:
            l = mid + 1
        else:
            r = mid - 1
    return [l, s - 2 * l]
for _ in range(int(input())):
    m = int(input())
    n = 1
    cur = 1
    ans = []
    fl = 0
    while cur + 2 * n < m:
        ans.append(n)
        cur += 2 * n
        n *= 2
        fl = 1
    if fl:
        n //= 2
        cur -= 2 * n
        ans.pop(-1)
        ans += bin(n, m - cur - 2 * n)
    else:
        if m == 2:
            ans = [0]
        else:
            ans = [1]
    print(len(ans))
    print(*ans)
