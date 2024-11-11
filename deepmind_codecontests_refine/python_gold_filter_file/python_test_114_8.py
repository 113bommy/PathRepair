for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split(" ")))
    b = sorted(a)
    for i in range(n//2):
        print(b[-(i + 1)], b[0])