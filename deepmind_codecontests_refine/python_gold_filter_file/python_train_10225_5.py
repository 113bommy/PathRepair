n, m = map(int, input().split())
trees = set(list(map(int, input().split())))
vis = set(trees)
res = []
dist = 0
for d in range(1, m+1):
    done = False
    removal = set()
    for t in trees:
        if t-d in vis and t+d in vis:
            removal.add(t)
        if not t-d in vis:
            vis.add(t-d)
            res.append(t-d)
            dist += d
        if len(res) == m:
            done = True
            break
        if not t+d in vis:
            vis.add(t+d)
            res.append(t+d)
            dist += d
        if len(res) == m:
            done = True
            break
    if done:
        break
    for t in removal:
        trees.remove(t)
print(dist)
print(' '.join(map(str, sorted(res))))
    
        
