for tests in range(int(input())):
    n, d = map(int,input().split())
    upper_bound, lower_bound, lv = n * (n - 1) // 2, 0, 0
    for i in range(1, n + 1):
        if not(i & (i - 1)):
            lv += 1
        lower_bound += lv - 1
    if not(d in range(lower_bound, upper_bound + 1)):
        print("NO")
    else:
        bad = [False] * n
        depth = list(range(n))
        count_child = [1] * n
        count_child[n - 1] = 0
        current_depth = upper_bound
        parent = list(range(-1,n-1))
        while current_depth > d:
            v, p = -1, -1
            for i in range(n):
                if not(bad[i]) and count_child[i] == 0 and (v == -1 or depth[i] < depth[v]):
                    v = i
            for i in range(n):
                if count_child[i] < 2 and depth[i] == depth[v] - 2 and (p == -1 or depth[i] > depth[p]):
                    p = i
            if p == -1:
                bad[v] = True
                continue
            count_child[parent[v]] -= 1
            depth[v] -= 1
            count_child[p] += 1
            parent[v] = p
            current_depth -= 1
        print("YES")
        print(*((parent[i] + 1) for i in range(1,n)))