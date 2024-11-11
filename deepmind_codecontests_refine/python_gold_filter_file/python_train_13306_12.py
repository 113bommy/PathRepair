L = int(input())

N = 1
l = L
while l // 2 >= 1:
    N += 1
    l //= 2

G = [[] for _ in range(N + 1)]

for i in range(1, N):
    G[i].append([i + 1, 0])
    G[i].append([i + 1, 2 ** (N - 1 - i)])

M = 2 * (N - 1)
tmp = 2 ** (N - 1)

for i in range(N - 2, -1, -1):
    if (L >> i) & 1:
        G[1].append([N - i, tmp])
        tmp += 2 ** i
        M += 1

if N > 20 or M > 60:
    print ('error')

print (N, M)
for i in range(1, N):
    for j in G[i]:
        print (i, *j)