n, m = map(int, input().split())

ans = []

if m == 1:
    print(1)
if (m <= n or m <= 2*n) and m != 1:
    for i in range(1, m+1):
        if i <= m:
            ans.append(i)
        else:
            break

if m > 2*n:
    for i in range(1, 2*n +1):
        if 2*n + i <= m:
            ans.append(2*n+i)
        if i <= m:
            ans.append(i)

print(*ans, end = ' ')