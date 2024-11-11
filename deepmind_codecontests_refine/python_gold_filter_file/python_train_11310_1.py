n, m, k = map(int, input().split())
mat = []
for i in range(n):
    s = input()
    mat.append([])
    for j in range(m):
        if s[j] == '*':
            mat[i].append(0)
        else:
            mat[i].append(1)

ans = 0
for i in range(n):
    res = 0
    for j in range(m):
        if mat[i][j]:
            res += 1
            if res >= k:
                ans += 1
        else:
            res = 0

for i in range(m):
    res = 0
    for j in range(n):
        if mat[j][i]:
            res += 1
            if res >= k:
                ans += 1
        else:
            res = 0

if k == 1:
    ans //= 2

print (ans)
