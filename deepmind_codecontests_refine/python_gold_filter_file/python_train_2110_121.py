t = int(input())

for _ in range(t):
    n = int(input())
    print(*[i for i in range(n, 0, -1)])