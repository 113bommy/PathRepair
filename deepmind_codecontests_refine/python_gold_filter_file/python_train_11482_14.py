t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for j in range(n):
        a[j] = (a[j], j)
    a.sort()
    if a[-1][0] == a[0][0]:
        print("NO")
        continue
    else:
        print("YES")
        d = [[a[0][1]]]
        last = a[0][0]
        for j in range(1, n):
            if a[j][0] == last:
                d[-1].append(a[j][1])
            else:
                d.append([a[j][1]])
                last = a[j][0]
        for j in range(len(d) - 1):
            for el in d[j]:
                print(el + 1, d[j + 1][0] + 1)
        if len(d[-1]) > 1:
            for el in d[-1][1:]:
                print(el + 1, d[0][0] + 1)