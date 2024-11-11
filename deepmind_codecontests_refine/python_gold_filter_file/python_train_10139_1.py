[n, m] = map(int, input().split())

q = n // m
r = n % m

list_1 = []

for i in range(r):
    list_1.append(q + 1)

for i in range(m - r):
    list_1.append(q)


print(*list_1)