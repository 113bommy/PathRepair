for i in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    s.sort(reverse=True)
    print(*s)