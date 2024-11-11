t = int(input())
for _ in range(t):
    m, n = map(int, input().split())
    topn = (1 << n) - 1
    data = [int(input(), 2) for _ in range(m)]
    data.sort()
    data.reverse()

    median = topn // 2
    expected = (topn - m) // 2
    base = max(median - 200, 0)
    top = min(median + 200, topn)
    
    l = base
    for x in range(base, top + 1):
        l += 1
        while data and data[-1] <= x:
            data.pop()
            l -= 1
        if l - 1 == expected:
            num = bin(x)[2:]
            print('0' * (n - len(num)) + num)
            break
