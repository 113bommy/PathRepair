for _ in range(int(input())):
    n = int(input())
    c = list(map(int, input().split()))
    print(0 if sum(c) % n == 0 else 1)