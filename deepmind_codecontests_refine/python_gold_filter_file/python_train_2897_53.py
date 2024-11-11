n = int(input())
s = [input() for _ in range(n)]
t = []
for i in range(n):
    t.append(s[i] + s[i])
t = t + t
ans = 0
for i in range(n):
    ok = True
    for j in range(n):
        for k in range(n):
            if t[i+j][k] != t[i+k][j]: 
                ok = False
                break
        if not ok: break
    if ok: ans += 1
print(ans * n)