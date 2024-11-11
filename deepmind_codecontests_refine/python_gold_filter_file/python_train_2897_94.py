N = int(input())
S = [list(input()) for i in range(N)]

ans = 0
flg = False
for a in range(N):
    S2 = S[a:] + S[:a]
    for i in range(N):
        for j in range(N):
            if S2[i][j] != S2[j][i]:
                flg = True
                break
        if flg:
            flg = False
            break
    else:
        ans += 1

print(ans * N)