n, m = map(int, input().split())

primes = [1 for _ in range(10**6+1)]

primes[0] = False
primes[1] = False

for i in range(2, 10**6):
    if primes[i]:
        for j in range(i*i, 10**6, i):
            primes[j] = False


grid = []
for i in range(n):
    grid.append([])
    line = list(map(int, input().split()))
    for nb in line:
        copy = nb
        while primes[nb] ^ 1:
            nb += 1
        grid[i].append(nb-copy)

ans = 10 ** 9

for i in range(n):
    ans = min(ans, sum(grid[i]))

for j in range(m):
    ans = min(ans, sum(grid[i][j] for i in range(n)))

print(ans)