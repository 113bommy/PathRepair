for _ in range(int(input())):
    a, b, c = [list(input()) for _ in range(3)]
    for i in range(len(a)):
        if c[i] == a[i]:
            b[i], c[i] = c[i], b[i]
        else:
            a[i], c[i] = c[i], b[i]
    print(('NO', 'YES')[a == b])
