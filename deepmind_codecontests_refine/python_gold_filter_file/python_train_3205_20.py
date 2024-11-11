N, M = map(int, input().split())
H = list(map(int, input().split()))

l = [1] * N

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if H[a] >= H[b]:
        l[b] = 0
    if H[a ]<= H[b]:
        l[a] = 0

print(sum(l))

