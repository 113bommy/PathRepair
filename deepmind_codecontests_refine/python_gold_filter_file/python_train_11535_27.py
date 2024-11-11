h,w = map(int, input().split())
a = [list(map(int, input().split())) for i in range(h)]
b = [list(map(int, input().split())) for i in range(h)]
m = 13120
DP = [[[0]*m for i in range(w)] for i in range(h)]

for i in range(h):
    for j in range(w):
        k = abs(a[i][j]-b[i][j])
        if i==0 and j==0:
            DP[i][j][k] = 1
        else:
            for l in range((i+j+1)*80+1):
                DP[i][j][l] = DP[i][j-1][abs(l-k)] | DP[i][j-1][l+k] | DP[i-1][j][abs(l-k)] | DP[i-1][j][l+k]
print(DP[-1][-1].index(1))