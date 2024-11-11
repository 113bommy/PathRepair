for _ in range(int(input())):
    n = int(input())
    a = set([int(i) for i in input().split()])
    m = min(a)
    a -= {m}
    i = 0
    while i < n // 2 and a:
        p = a.pop()
        i += 1
        print(p, m)
    if i < n // 2:
        print(1 / 0)