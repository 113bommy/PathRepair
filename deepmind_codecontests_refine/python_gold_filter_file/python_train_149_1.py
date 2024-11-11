n, m = map(int, input().split())
w = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = list()
used = [False] * (n + 1)
for i in range(len(b)):
    if not used[b[i]]:
        ans.append(b[i])
        used[b[i]] = True
anss = 0
for i in range(len(b)):
    top = -1
    for j in range(len(ans)):
        if ans[j] == b[i]:
            top = ans[j]
            
            for k in range(j, 0, -1):
                ans[k] = ans[k - 1]
                anss += w[ans[k - 1] - 1]
            break
    ans[0] = top
print(anss)
