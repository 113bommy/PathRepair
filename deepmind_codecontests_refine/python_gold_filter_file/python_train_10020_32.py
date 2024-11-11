from collections import defaultdict
itl = lambda: list(map(int, input().strip().split()))


def dfs(u, p, edges):
    count = 1
    for v in edges[u]:
        if v != p:
            count += dfs(v, u, edges)
    return count


def solve():
    n, x = itl()
    edges = defaultdict(list)
    for _ in range(n - 1):
        u, v = itl()
        edges[u].append(v)
        edges[v].append(u)
    
    if len(edges[x]) <= 1:
        return "Ayush" 
    
    ans = 0
    for u in edges[x]:
        ans += dfs(u, x, edges)

    if len(edges[x]) == 2:
        return "Ashish" if (ans - 2) % 2 == 0 else "Ayush"
    else:
        return "Ayush" if (ans - 3) % 2 == 0 else "Ashish"

        
if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        print(solve())