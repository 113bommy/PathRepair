t = int(input())
for i in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    new_a = []
    now = a[0]
    s = 1
    for i in range(1, n):
        if a[i] == now:
            s += 1
        else:
            new_a.append([now, s])
            s = 1
            now = a[i]
    new_a.append([now, s])
    p = {}
    a = list(set(a))
    for i in range(len(a)):
        p[a[i]] = [0]
    for i in range(len(new_a)):
        for j in p.keys():
            if j == new_a[i][0]:
                p[j].append(p[j][-1] + new_a[i][1])
            else:
                p[j].append(p[j][-1])
    ans = -1
    for i in range(len(new_a)):
        for j in range(i, len(new_a)):
            mx = -1
            good_color = -1
            for k in a:
                counter_color = p[k][j + 1] - p[k][i]
                if counter_color > mx:
                    mx = max(mx, counter_color)
                    good_color = k
            for k in a:
                first = p[k][i] - p[k][0]
                second = p[k][len(new_a)] - p[k][j + 1]
                ans = max(ans, mx + 2 * min(first, second))
    for i in a:
        ans = max(ans, p[i][-1])
    print(ans)