import sys
input = sys.stdin.readline

Q = int(input())
Query = []
for _ in range(Q):
    N, X = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)
    Query.append((N, X-1, graph))

for N, s, graph in Query:
    checked = [False]*N
    checked[s] = True
    odd = 0
    for b in graph[s]:
        q = [b]
        checked[b] = True
        Count = 1
        while q:
            qq = []
            for p in q:
                for np in graph[p]:
                    if not checked[np]:
                        checked[np] = True
                        qq.append(np)
                        Count += 1
            q = qq
        if Count%2 == 1:
            odd += 1
    if len(graph[s]) <= 1 or odd%2 == 1:
        print("Ayush")
    else:
        print("Ashish")