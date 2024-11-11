from math import inf
import statistics
import itertools


def min_tree_paint(v, graph, colors):

    start = graph.index(min(graph, key=lambda z: len(z)))
    combs = list(itertools.permutations([0, 1, 2]))

    for k in graph:
        if len(k) >= 3:
            print('-1')
            return

    min_cost = inf
    
    min_path = dict()
    for c in combs:
        x = start
        count = 0
        cost = 0
        path = dict()
        last_x = -1
        while True:
            chosen = c[count % 3]
            cost += colors[chosen][x]
            path[x] = chosen
            if count != 0 and len(graph[x]) == 1:
                break
            for y in graph[x]:
                if y != last_x:
                    last_x = x
                    x = y
                    break
            count += 1

        if cost < min_cost:
            min_path = path.copy()
            min_cost = cost

    print(min_cost)
    for x in range(v):
        print(min_path[x]+1, end=' ')
    print()


v = int(input())
c1 = list(map(int, input().split()))
c2 = list(map(int, input().split()))
c3 = list(map(int, input().split()))
colors = [c1, c2, c3]
graph = [[] for _ in range(v)]
for _ in range(v-1):
    arr = list(map(int, input().split()))
    graph[arr[0]-1].append(arr[1]-1)
    graph[arr[1]-1].append(arr[0]-1)
min_tree_paint(v, graph, colors)
