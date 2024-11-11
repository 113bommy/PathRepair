

q = int(input())

for _ in range(q):
    n, k = map(int, input().split())
    A = [int(x) for x in input().split()]

    a, b = 0, 2 * 10**8 + 1

    for x in A:
        a = max([a, x - k])
        b = min([b, x + k])

    print(-1 if b < a else b)
