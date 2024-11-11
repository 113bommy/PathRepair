if __name__ == '__main__':
    n, m = map(int, input().split())
    es = [None] * n
    for i in range(n):
        es[i] = []

    for a, b in (map(lambda x: int(x) - 1, input().split()) for _ in range(m)):
        es[a].append(b)
        es[b].append(a)

    if m % 2:
        print(-1)
        quit(0)

    mst_es = [None] * n
    for i in range(n):
        mst_es[i] = set()
    st = []
    used = [False] * n
    st.append(0)
    used[0] = True
    degrees = [0] * n
    num_edges = [0] * n
    while st != []:
        v = st.pop()
        for u in es[v]:
            if used[u]:
                if v not in mst_es[u] and u < v:
                    print(u + 1, v + 1)
                    degrees[u] += 1
            else:
                num_edges[u] += 1
                num_edges[v] += 1
                used[u] = True
                a, b = (u, v) if u < v else (v, u)
                st.append(u)
                mst_es[a].add(b)
                mst_es[b].add(a)

    st = [v for v in range(n) if num_edges[v] == 1]
    while st != []:
        v = st.pop()
        if num_edges[v] < 1:
            continue
        for u in mst_es[v]:
            a, b = (v, u) if degrees[v] % 2 == 1 else (u, v)
            print(a + 1, b + 1)
            degrees[a] += 1
        num_edges[u] -= 1
        num_edges[v] -= 1
        mst_es[v].remove(u)
        mst_es[u].remove(v)
        if num_edges[u] == 1:
            st.append(u)

