t = int(input())
for x in range(t):
    a = list(range(1, int(input()) + 1))
    a.sort(reverse=True)
    print(*a)