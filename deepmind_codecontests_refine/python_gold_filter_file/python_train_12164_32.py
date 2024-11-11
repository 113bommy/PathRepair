N = int(input())
T = [int(_) for _ in input().split()]
for i in range(N - 1):
    T[i + 1] += T[i]
T = [0] + T
V = [int(_) for _ in input().split()]
V = V
vel = [min(i / 2, T[-1] - i / 2) for i in range(2 * T[-1] + 1)]
for i in range(N):
    for j in range(2 * T[-1] + 1):
        vel[j] = min(vel[j],
                     max(V[i], -j / 2 + T[i] + V[i], j / 2 - T[i + 1] + V[i]))
print((2 * sum(vel) - vel[0] - vel[-1]) / 4)
