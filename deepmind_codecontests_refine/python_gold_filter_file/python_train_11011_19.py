N, K = map(int, input().split())
A = list(map(int, input().split()))

for _ in range(min(K, 50)):
    lamp = [0 for i in range(N + 1)]
    for i in range(N):
        lamp[max(0, i - A[i])] += 1
        lamp[min(N, i + A[i] + 1)] -= 1

    for i in range(1, N + 1):
        lamp[i] += lamp[i - 1]
    A = lamp

[print(A[i], end=' ') for i in range(N)]
print()
