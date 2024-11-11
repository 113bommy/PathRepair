for t in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    a.sort(reverse=True)
    print(*a)