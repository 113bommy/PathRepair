N, K = map(int, input().split())
A = [int(s) for s in input().split()]

ru = [None] * (N+1)
ru[0] = 0
for i in range(len(A)):
    ru[i+1] = ru[i] + A[i]

ans = 0
for m in reversed(range(40)):
    cnt = 0
    for i in range(N):
        for j in range(i+1, N+1):
            sum = ru[j] - ru[i]
            if (sum & ans) < ans:
                continue
            if sum & (1 << m):
                cnt += 1
    if cnt >= K:
        ans |= (1 << m)

print(ans)