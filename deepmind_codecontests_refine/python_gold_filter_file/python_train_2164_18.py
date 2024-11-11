def main():
    import heapq
    inf = 10**16
    n, m, s = map(int, input().split())
    uvab = [list(map(int, input().split())) for _ in [0]*m]
    cd = [list(map(int, input().split())) for _ in [0]*n]
    g = [[] for _ in [0]*n]
    [g[a-1].append([b-1, c, d]) for a, b, c, d in uvab]
    [g[b-1].append([a-1, c, d]) for a, b, c, d in uvab]
    vertex = [[inf]*2501 for _ in [0]*n]
    h = [(0, 0, min(s, 2500))]  # 時刻、位置、所持金
    heapq.heapify(h)
    while h:
        t, p, money = heapq.heappop(h)
        if vertex[p][money] != inf:
            continue
        vertex[p][money] = t
        newmoney = min(money+cd[p][0], 2500)
        if vertex[p][newmoney] == inf:
            heapq.heappush(h, (t+cd[p][1], p, newmoney))
        for a, b, c in g[p]:  # 行き先、運賃、時間
            if money < b:
                continue
            if vertex[a][money-b] != inf:
                continue
            heapq.heappush(h, (t+c, a, money-b))
    for i in vertex[1:]:
        print(min(i))


main()
