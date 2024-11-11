N, C, K = [int(i) for i in input().split()]
T = sorted([int(input()) for i in range(N)])
ans = 1
limit = 0
ti = T[0]
for i in range(N - 1):
    limit += 1
    if ti + K < T[i + 1] or limit == C:
        ti = T[i + 1]
        ans += 1
        limit = 0
print(ans)
