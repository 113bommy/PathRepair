t = int(input())
for whatever in range(t):
    n, c0, c1, h = map(int, input().split())
    s = str(input())
    ans = 0
    for c in s:
        if c == '0':
            ans += min(c0, c1 + h)
        else:
            ans += min(c1, c0 + h)
    print(ans)