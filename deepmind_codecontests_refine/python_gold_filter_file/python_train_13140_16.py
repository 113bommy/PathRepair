for _ in range(int(input())):
    n = int(input())
    print(*sorted(map(int, input().split()), reverse=True))