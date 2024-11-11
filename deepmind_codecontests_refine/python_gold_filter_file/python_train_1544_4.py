N, X = map(int, input().split())
x = list(map(int, input().split()))

y = [x[0]]
for i in range(N-1):
    x[i+1] += x[i]
    y.append(x[i+1])

ans = 10**21
for k in range(1, N+1):
    num = N
    memo = k * X + X * N
    i = 0
    while num > k:
        memo += max(i+3, 5) * (y[num-1] - y[num-1-k])
        num -= k
        i += 2
    memo += max(i+3, 5) * (y[num-1])
    ans = min(ans, memo)

print(ans)
