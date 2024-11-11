def insertion_sort(r, n, g):
    global cnt
    for i in range(g, n):
        v = r[i]
        j = i - g
        while v < r[j] and j >= 0:
            r[j + g] = r[j]
            j = j - g
            cnt += 1
        r[j + g] = v


def shell_sort(r, n):
    global m
    global G
    h = 1
    while True:
        if h > n:
            break
        G.append(h)
        h = h * 3 + 1
    m = len(G)
    G.reverse()
    for i in range(m):
        insertion_sort(r, n, G[i])

cnt = 0
G = []
m = 0
N = int(input())
R = [int(input()) for i in range(N)]
shell_sort(R, N)
print(m)
print(*G)
print(cnt)
for i in range(N):
    print(R[i])