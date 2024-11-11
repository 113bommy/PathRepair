N, K = map(int, input().split())
*A, = map(int, input().split())
for _ in range(min(K, 50)):
    counter = [0] * (N+2)
    for i, a in enumerate(A, 1):
        counter[max(0, i - a)] += 1
        counter[min(N + 1, i + a + 1)] += -1
    for i in range(1, len(counter) - 1):
        counter[i] += counter[i-1]
    A = counter[1:N+1]
print(*A)
