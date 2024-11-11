for t in range(int(input())):
    a, b = map(int, input().split())
    a = abs(a - b)
    print(a // 5 + (a % 5 + 1) // 2)
