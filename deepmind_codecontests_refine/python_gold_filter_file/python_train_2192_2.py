nv, ne = map(int, input().split())

costs = [[None] * nv for _ in range(nv)]
for i in range(nv):
    costs[i][i] = 0

while ne:
    s, t, d = map(int, input().split())
    costs[s][t] = d
    ne -= 1


def loop():
    for k in range(nv):
        for i in range(nv):
            for j in range(nv):
                if costs[i][k] is None or costs[k][j] is None:
                    continue
                tmp_cost = costs[i][k] + costs[k][j]
                if i == j and tmp_cost < 0:
                    print('NEGATIVE CYCLE')
                    return False
                if costs[i][j] is None or costs[i][j] > tmp_cost:
                    costs[i][j] = tmp_cost
    return True


if loop():
    for vc in costs:
        print(*('INF' if c is None else c for c in vc))