t = int(input())
a = set(chr(x) for x in range(97, 123))
for _ in range(t):
    s = input()
    adj = dict()
    aa = set(s)
    for c in aa:
        adj[c] = set()
    for i in range(len(s)-1):
        adj[s[i]].add(s[i+1])
        adj[s[i+1]].add(s[i])

    ans = []
    flag = True
    visited = set()
    for k, v in adj.items():
        if k in visited:
            continue
        if len(v) > 2:
            flag = False
            break
        elif len(v) == 1:
            c = k
            while True:
                ans.append(c)
                visited.add(c)
                if len(adj[c]) > 1:
                    flag = False
                    break
                if not adj[c]:
                    break
                c = adj[c].pop()
                adj[c].remove(ans[-1])
        elif len(v) == 0:
            visited.add(c)
            ans.append(c)

    if not flag or aa != visited:
        print('NO')
    else:
        print('YES')
        print(*(ans + list(a - aa)), sep='')
