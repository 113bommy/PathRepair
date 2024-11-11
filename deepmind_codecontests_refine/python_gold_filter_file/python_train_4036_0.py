def main():
    n = int(input())
    neis = [[] for _ in range(n + 1)]
    common = None
    max_deg = 0
    for _ in range(n - 1):
        u, v = map(int, input().split())
        neis[u].append(v)
        neis[v].append(u)
        if len(neis[u]) > max_deg:
            max_deg = len(neis[u])
            common = u
        if len(neis[v]) > max_deg:
            max_deg = len(neis[v])
            common = v

    def get_path(start, cur):
        path = [start]
        while True:
            if len(neis[cur]) == 1:
                return (True, cur)
            else:
                pre = path[-1]
                vers = set(neis[cur])
                vers.remove(pre)
                if len(vers) > 1:
                    return (False, None)
                else:
                    path.append(cur)
                    cur = vers.pop()

    def fake_dfs(common):
        nonlocal neis

        paths = []
        for nei in neis[common]:
            is_path, end_ver = get_path(common, nei)
            if is_path:
                paths.append((common, end_ver))
            else:
                print('No')
                return

        print('Yes')
        print(len(paths))
        for u, v in paths:
            print(u, v)

    fake_dfs(common)


if __name__ == '__main__':
    main()
