def solve():
    base = []
    for a, s in zip(A[::-1], S[::-1]):
        x = a
        for y in base:
            x = min(x, x ^ y)
        if s == "0":
            if x:
                base.append(x)
        else:
            if x:
                return 1
    return 0


t = int(input())
for i in range(t):
    n = int(input())
    *A, = map(int, input().split())
    S = input()
    print(solve())
