h,w = map(int,input().split())
c = [list(map(int,input().split())) for _ in range(10)]
a = [list(map(int,input().split())) for _ in range(h)]
n = 10
for k in range(n):
    for i in range(n):
        for j in range(n):
            c[i][j] = min(c[i][j],c[i][k]+c[k][j])
ans = 0
for i in a:
    for j in i:
        if j!=-1: ans += c[j][1]
print(ans)