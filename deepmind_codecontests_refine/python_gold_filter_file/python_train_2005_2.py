for t in range(int(input())):
    n = int(input())
    a = list(map(int, input()))
    b = list(map(int, input()))
    c = 0
    d = []
    i = n - 1
    while i > 0:
        if a[i] != b[i]:
            if a[i] == a[0]:
                c += 1
                d.append(i + 1)
                s = [1 - a[i-j] for j in range(i+1)]
                s.extend(a[i+1:])
                a = s
            else:
                c += 2
                d.append(1)
                a[0] = 1 - a[0]
                d.append(i + 1)
                s = [1 - a[i-j] for j in range(i + 1)]
                s.extend(a[i + 1:])
                a = s
        i -= 1
    if a[0] != b[0]:
        c += 1
        d.append(1)
    print(c, *d)
