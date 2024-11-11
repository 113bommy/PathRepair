import itertools
n, k = map(int, input().split())
d = list(map(int, input().split()))
u = []
for i in range(0, 10):
    if i not in d:
        u.append(i)
for j in range(1, 6):
    for i in itertools.product(u, repeat=j):
        t = int("".join(map(str, i)))
        if n <= t <= 100000:
            print(t)
            exit()
