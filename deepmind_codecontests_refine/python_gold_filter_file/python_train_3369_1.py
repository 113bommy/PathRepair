n = 100
g = [set() for i in range(n)]
k = int(input())
ans = 0
flag = False
for l in range(n):
    for r in range(l + 1):
        if l == r or l in g[r]:
            continue
        count = 0
        for u in range(n):
            if u == l or u == r:
                continue
            if l in g[u] and r in g[u]:
                count += 1
        if count + ans <= k:
            ans += count
            g[l].add(r)
            g[r].add(l)            
        if ans == k:
            flag = True
            break
    if flag:
        break
ans = [[0 for i in range(n)] for j in range(n)]
print(100)
for i in range(n):
    for j in range(n):
        if j in g[i]:
            ans[i][j] = 1
    print(*ans[i], sep='')
    
        
    