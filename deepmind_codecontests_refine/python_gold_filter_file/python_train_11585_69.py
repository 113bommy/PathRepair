for _ in range(int(input())):
    a,b = map(int,input().split())
    print((abs(b - a) + 9) // 10)