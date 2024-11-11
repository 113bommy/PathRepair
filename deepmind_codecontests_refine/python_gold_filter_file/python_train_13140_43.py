for _ in range(int(input())):
    n = input()
    print(*sorted(map(int, input().split()))[::-1])