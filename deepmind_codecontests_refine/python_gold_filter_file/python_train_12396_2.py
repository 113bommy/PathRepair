while True:
    x = list(map(int, input().split()))
    if x[0] == x[1] == 0:
        break
    print(min(x), max(x))