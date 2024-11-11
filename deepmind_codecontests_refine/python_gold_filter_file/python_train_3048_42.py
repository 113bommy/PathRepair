for _ in range(int(input())):
    a, b = map(int, input().split())
    n = a & b
    print((a^n) + (b^n))
