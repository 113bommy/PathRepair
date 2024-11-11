N = int(input())
As =[list(map(int, input().split())) for _ in range(N)]
flag1 = False
ans = 0
for i in range(N):
    for j in range(i+1, N):
        flag2 = True
        for k in range(N):
            if k == i or k == j:
                continue
            if As[i][k]+As[k][j] < As[i][j]:
                flag1 = True
                break
            elif As[i][k]+As[k][j] == As[i][j]:
                flag2 = False
        if flag2:
            ans += As[i][j]
        if flag1:
            break
    if flag1:
        break
if not flag1:
    print(ans)
else:
    print(-1)