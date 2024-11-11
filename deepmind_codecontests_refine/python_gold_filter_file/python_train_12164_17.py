N = int(input())
T = list(map(int, input().split()))
V = [0] + list(map(int, input().split())) + [0]

Tc = [0, 0] + [sum(T[:i + 1]) for i in range(N)] + [sum(T)]

ans = 0
for i in range(sum(T) * 2):
    t1, t2 = i * 0.5, (i + 1) * 0.5
    maxV1, maxV2 = [], []
    for j in range(N + 2):
        for t, maxV in [(t1, maxV1), (t2, maxV2)]:
            if t <= Tc[j]:
                maxV.append(V[j] + (Tc[j] - t))
            elif Tc[j] < t <= Tc[j + 1]:
                maxV.append(V[j])
            else:
                maxV.append(V[j] + (t - Tc[j + 1]))
    ans += 0.25 * (min(maxV1) + min(maxV2))

print(ans)
