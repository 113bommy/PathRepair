def check(c):
    l = [['.']*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            l[(i+c)%n][j] = s[i][j]
    for i in range(n):
        for j in range(n):
            if l[i][j]!=l[j][i]:
                return False
    return True
n = int(input())
s = [input() for _ in range(n)]
ans = 0
for c in range(n):
    if check(c):
        ans+=n
print(ans)