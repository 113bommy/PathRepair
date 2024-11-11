def solve(a, b):
    diff = b - a
    if diff == 0:
        return diff
    elif diff > 0:
        if diff % 2 == 0:
            return 2
        else:
            return 1
    else:
        if diff % 2 == 0:
            return 1
        else:
            return 2

t = int(input())
for _ in range(0, t):
    a, b = map(int, input().split())
    print(solve(a, b))