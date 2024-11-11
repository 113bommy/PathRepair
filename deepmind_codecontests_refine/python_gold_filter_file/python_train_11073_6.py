n = int(input())
if n <= 2:
    print(-1)
else:
    numbers = [x for x in range(n, 0, -1)]
    print(" ".join(map(str, numbers)))