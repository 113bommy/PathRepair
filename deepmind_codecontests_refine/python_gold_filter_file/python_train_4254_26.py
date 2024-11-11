N, M = map(int, input().split())
c = [0] * (N+1)

for _ in range(M):
    a, b = map(int, input().split())
    c[a] += 1
    c[b] += 1

print("YES" if all(c[i]%2 == 0 for i in range(N+1)) else "NO")