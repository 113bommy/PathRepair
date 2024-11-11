input()

b = list(map(int, input().split()))
a, x = list(), 0

for v in b:
    a.append(x + v)
    x = max(x, a[-1])

print(*a)