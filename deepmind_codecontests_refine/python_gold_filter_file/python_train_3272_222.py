n = int(input())
a = list(map(int, input().split()[:n]))
a.sort()
print(*a)
