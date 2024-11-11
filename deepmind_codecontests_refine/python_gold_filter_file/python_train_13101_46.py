N, C, K = map(int, input().split(' '))
bus = []
ans = 0
T = [int(input()) for _ in range(N)]
T.sort()

min_t = 0
i = 0
while i < N:
    ans += 1
    start = i
    while i < N and T[i] - T[start] <= K and i - start < C:
        i += 1
print(ans)