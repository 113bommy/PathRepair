for _ in range(int(input())):
    n = int(input())
    print(*sorted(list(map(int,input().split())),reverse=True))