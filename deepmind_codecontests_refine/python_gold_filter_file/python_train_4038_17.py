n, m, x = map(int, input().split())
ca = [list(map(int, input().split())) for _ in range(n)]

ans = 12*10**6
for i in range(2**n):
    s = [0]*(m+1)
    for j in range(n):
        if (i>>j) & 1 == 1:
            for k in range(m+1):
                s[k] += ca[j][k]
    for j in range(1, m+1):
        if s[j] < x:
            break
    else:
        ans = min(ans, s[0])
print(-1 if ans == 12*10**6 else ans)