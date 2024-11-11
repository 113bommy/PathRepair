for i in range(int(input())):
    a, b = map(int, input().split())
    print((abs(a - b) - 1) // 10 + 1)