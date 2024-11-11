n, m = map(int, input().split())
edges_from = [[] for _ in range(n)]

for _ in range(m):
    _from, to = map(lambda x: int(x)-1, input().split())
    edges_from[_from].append(to)

E_dist_to_goal = [0] * n
for node in range(n-2, -1, -1):
    routes = edges_from[node]
    num_of_routes = len(routes)
    for next_node in routes:
        dist = E_dist_to_goal[next_node] + 1
        E_dist_to_goal[node] += dist/num_of_routes


def recalculate_dist(node, E_dist_to_goal):
    recal_E_dist = [0]*(node+1)
    routes = edges_from[node]
    num_of_routes = len(routes)
    if num_of_routes == 1:
        return False

    heaviest_route = max(E_dist_to_goal[next_node]+1 for next_node in routes)
    new_dist = E_dist_to_goal[node] - heaviest_route/num_of_routes
    new_dist *= num_of_routes / (num_of_routes - 1)
    recal_E_dist[node] = new_dist

    for v in range(node-1, -1, -1):
        routes = edges_from[v]
        num_of_routes = len(routes)
        for nv in routes:
            if nv > node:
                dist = E_dist_to_goal[nv] + 1
            else:
                dist = recal_E_dist[nv] + 1
            recal_E_dist[v] += dist
        recal_E_dist[v] /= num_of_routes
    return recal_E_dist[0]


ans = [E_dist_to_goal[0]]
for i in range(n-2):
    candidate = recalculate_dist(i, E_dist_to_goal)
    if candidate:
        ans.append(candidate)

print(min(ans))
