N = int(input())
a = list(map(int, input().split()))

t = [0] * (N + 1)
for i in range(N, 0, -1):
    t[i] = (sum(t[2 * i::i]) % 2) ^ a[i - 1]

print(sum(t))
print(*[i for i in range(1, N + 1) if t[i] == 1])
