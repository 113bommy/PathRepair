for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(0 if sum(a) % n == 0 else 1)