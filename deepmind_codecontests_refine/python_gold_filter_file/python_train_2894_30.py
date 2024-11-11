N, Q = map(int, input().split())

dictionary = [[] for i in range(N + 1)]

for i in range(N-1):
    a, b = map(int, input().split())
    dictionary[a].append(b)

num = [0] * (N + 1)

for i in range(Q):
    p, x = map(int, input().split())
    num[p] += x

for i in range(1, N + 1):
    print(num[i])
    for j in range(0, len(dictionary[i])):
        num[dictionary[i][j]] += num[i]


