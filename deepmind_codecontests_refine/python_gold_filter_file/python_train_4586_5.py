import itertools

while True:
    n, x = map(int, input().split())
    if n == x == 0:
        break
    result = 0
    for i in itertools.combinations(range(1, n + 1), 3):
        if sum(i) == x:
            result += 1
    print(result)