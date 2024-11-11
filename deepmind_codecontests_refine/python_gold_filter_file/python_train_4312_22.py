def f():
    n = int(input()) - 1
    x = list(map(int, input().split()))
    p = [(x[i], x[i + 1]) if x[i] < x[i + 1] else (x[i + 1], x[i]) for i in range(n)]
    p.sort()
    for j, (x, y) in enumerate(p, 1):
        while j < n and p[j][0] == x: j += 1
        while j < n and p[j][0] < y: 
            if p[j][1] > y: return 'yes'
            j += 1
    return 'no'
print(f())
    