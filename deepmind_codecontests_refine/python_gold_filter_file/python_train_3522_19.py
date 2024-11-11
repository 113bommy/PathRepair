N = int(input())
X = []
for _ in range(N-1):
    c, s, f = map(int, input().split())
    X.append((c, s, f))
for k in range(N):
    t = 0
    for i in range(k, N-1):
        c, s, f = X[i]
        t = -(-t//f) * f
        t = max(t, s)
        t += c
    print(t)