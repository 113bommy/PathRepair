def main():
    N = int(input())
    ab = [tuple(map(int, input().split())) for _ in range(N - 1)]

    to = [[] for _ in range(N)]
    for a, b in ab:
        to[a - 1].append(b - 1)
        to[b - 1].append(a - 1)

    c1 = list(range(1, N + 1, 3))
    c2 = list(range(2, N + 1, 3))
    c3 = list(range(3, N + 1, 3))

    color = [0] * N

    for root in range(N):
        if len(to[root]) == 1:
            break

    queue = set([root])
    color[root] = 1
    while queue:
        v = queue.pop()
        color_v = color[v]
        for i in to[v]:
            if color[i] == 0:
                color[i] = 3 - color_v
                queue.add(i)

    ans = [0] * N
    order = sorted(range(N), key=lambda x: color[x])
    if color.count(1) <= N / 3:
        for i in order:
            if c3:
                ans[i] = c3.pop(-1)
            elif c1:
                ans[i] = c1.pop(-1)
            else:
                ans[i] = c2.pop(-1)
    elif color.count(2) <= N / 3:
        for i in reversed(order):
            if c3:
                ans[i] = c3.pop(-1)
            elif c1:
                ans[i] = c1.pop(-1)
            else:
                ans[i] = c2.pop(-1)
    else:
        for i in range(N):
            if (color[i] == 1) and c1:
                ans[i] = c1.pop(-1)
            elif (color[i] == 2) and c2:
                ans[i] = c2.pop(-1)
            else:
                ans[i] = c3.pop(-1)

    print(*ans)


main()
