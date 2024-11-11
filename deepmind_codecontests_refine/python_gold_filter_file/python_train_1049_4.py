from sys import exit

def bad():
    print("NO")
    exit()

node = 1
def make_branch(u, d, deg, g, n, k):
    global node
    while deg[u] < k and d > 0 and node < n:
        node += 1
        deg[u] += 1
        deg[node] = 1
        g[u].append(node)
        make_branch(node, d - 1, deg, g, n, k)

def main():
    global node
    n, d, k = map(int, input().split())
    if d >= n or (k == 1 and n > 2):
        bad()

    g = [[] for _ in range(n + 5)]
    deg = [0 for _ in range(n + 5)]

    for i in range(1, d + 1):
        g[i].append(i + 1)
        deg[i] += 1
        deg[i + 1] += 1

    node = d + 1

    LD = 1
    RD = d - 1
    for u in range(2, d + 1):
        make_branch(u, min(LD, RD), deg, g, n, k)
        LD += 1
        RD -= 1

    used = [False for _ in range(n + 5)]
    q = [[1, 1]]
    used[1] = True
    while len(q) > 0:
        u, p = q.pop()
        for v in g[u]:
            if v != p:
                used[v] = True
                q.append([v, u])

    for i in range(1, n + 1):
        if used[i] == False:
            bad()

    print("YES")
    for u in range(1, n + 1):
        for v in g[u]:
            print(u, v)

main()


