for _ in range(int(input())):
    n = int(input())
    if (n * (n - 1) / 2) % 2 == 0:
        a = list(range(2, n + 1, 2))
        b = list(range(1, n - 1, 2))
        print("YES")
        print(*list(a + b + [sum(a) - sum(b)]))
    else:
        print("NO")