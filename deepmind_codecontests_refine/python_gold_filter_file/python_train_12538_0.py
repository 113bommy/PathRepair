def prime(n):
    n += 1
    p = [False] * n
    for i in range(3, int(n ** 0.5) + 1, 2):
        u, v = i * i, 2 * i
        if not p[i]: p[u :: v] = [True] * ((n - u - 1) // v + 1)
    p[4 :: 2] = [True] * ((n - 3) // 2)
    return p
n = int(input())
t = list(enumerate(list(map(int, input().split())), 1))
t.sort(key = lambda x: x[1])
t = [x[0] for x in t]
u, v, q = list(range(n + 1)), list(range(n + 1)), []
p = prime(n + 1)
for i, j in enumerate(t, 1):
    while i != u[j]:
        k = i
        while p[u[j] - k + 1]: k += 1
        q.append(str(k) + ' ' + str(u[j]))
        a, b = u[j], v[k]
        u[b], u[j], v[a], v[k] = a, k, b, j
print(len(q))
print('\n'.join(q))