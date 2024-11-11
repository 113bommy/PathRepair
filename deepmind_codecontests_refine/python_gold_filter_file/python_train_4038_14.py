n, m, x = map(int, input().split())
ca = [list(map(int, input().split())) for _ in range(n)]

ans = []

for i in range(2 ** n):
    jud = [0]*m
    money = 0
    for j in range(n):
        if (i >> j) & 1:
            money += ca[j][0]
            for k in range(m):
                jud[k] += ca[j][k+1]
    if min(jud) >= x:
        ans.append(money)

if not ans:
    print(-1)
else:
    print(min(ans))