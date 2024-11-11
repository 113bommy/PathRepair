n = int(input())
csf = [list(map(int, input().split())) for _ in range(n-1)]

for i in range(n):
    ans = 0
    for j in range(i, n-1):
        if csf[j][1] >= ans:
            ans = csf[j][0] + csf[j][1]
        else:
            ans = csf[j][0] + -(-ans //csf[j][2]) * csf[j][2]
    print(ans)