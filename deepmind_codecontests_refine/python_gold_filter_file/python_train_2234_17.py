n, m = map(int, input().split())
ans = 100000
if m > n:
    print(-1)
elif n == m:
    print(n)
else:
    for a in range(1, 10000):
        y = n-a*m

        x = a*m-y

        if y < 0 or x < 0:
            continue

        ans = min(ans, x+y)


    print(ans)