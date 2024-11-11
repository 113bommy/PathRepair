n, cur = int(input()), 0
for i in range(1, n):
    cur = (cur + i) % n
    print(cur + 1, end=' ')
