for _ in range(int(input())):
    n, t = map(int, input().split())
    values, colours, last = [int(i) for i in input().split()], [-1 for i in range(n)], 0
    for i in range(n):
        if values[i] == t / 2:
            if last % 2:
                colours[i] = 0
            else:
                colours[i] = 1
            last += 1
        elif values[i] > t / 2:
            colours[i] = 1
        else:
            colours[i] = 0
    print(*colours)
