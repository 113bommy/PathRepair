from collections import defaultdict
INF = float('inf')

n = int(input())
memo = defaultdict(lambda: INF)
for _ in range(n):
    cost, vit = input().split(' ')
    cost = int(cost)
    vit = tuple(sorted(list(vit)))
    memo[vit] = min(memo[vit], cost)

ta = tuple('A')
tb = tuple('B')
tc = tuple('C')

tab = ('A', 'B')
tbc = ('B', 'C')
tca = ('A', 'C')

tabc = ('A', 'B', 'C')

m = min(
    memo[ta] + memo[tb] + memo[tc],
    memo[tabc],
    memo[tab] + memo[tc],
    memo[tbc] + memo[ta],
    memo[tca] + memo[tb],
    memo[tab] + memo[tbc],
    memo[tab] + memo[tca],
    memo[tbc] + memo[tca],
    memo[ta] + memo[tb] + memo[tbc],
    memo[ta] + memo[tb] + memo[tca],
    memo[tc] + memo[tb] + memo[tca],
    memo[tc] + memo[tb] + memo[tab],
    memo[ta] + memo[tc] + memo[tbc],
    memo[ta] + memo[tc] + memo[tab],
)

if m == INF:
    m = -1

print(m)