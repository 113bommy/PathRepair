from collections import defaultdict
from collections import deque

for _ in range(int(input())):
    n, x = map(int, input().split())
    g = defaultdict(set)
    for _ in range(n - 1):
        a, b = map(int, input().split())
        g[a].add(b)
        g[b].add(a)

    if len(g[x]) <= 1:
        print('Ayush')
    else:
        print('Ayush' if n % 2 == 0 else 'Ashish')
