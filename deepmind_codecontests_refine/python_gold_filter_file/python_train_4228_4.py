n = int(input())
a = [int(item) for item in input().split()]
b = [int(item) for item in input().split()]

ans = a.copy()
both = []
cnt = [0] * (n + 1)

for i in range(n):
    if a[i] != b[i]:
        both.append(i)
    else:
        cnt[a[i]] = 1

if len(both) == 1:
    for i in range(1, n + 1):
        if cnt[i] == 0:
            ans[both[0]] = i

else:

    u, v = both
    nb = []
    for i in range(1, n + 1):
        if cnt[i] == 0:
            nb.append(i)
    
    if a[u] == nb[0] and b[v] == nb[1]:
        ans[u] = nb[0]
        ans[v] = nb[1]
    elif a[u] == nb[1] and b[v] == nb[0]:
        ans[u] = nb[1]
        ans[v] = nb[0]
    elif a[v] == nb[0] and b[u] == nb[1]:
        ans[v] = nb[0]
        ans[u] = nb[1]
    elif a[v] == nb[1] and b[u] == nb[0]:
        ans[v] = nb[1]
        ans[u] = nb[0]
    

print(" ".join(str(x) for x in ans))