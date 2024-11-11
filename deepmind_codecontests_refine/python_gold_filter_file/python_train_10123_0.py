
def main():
    n = int(input())
    if n < 3:
        print(-1)
        return

    ans = [[0]*n for _ in range(n)]
    st = n*n-9
    ans[0][0:3] = [st+6,st+5,st+8]
    ans[1][0:3] = [st+7,st+3,st+4]
    ans[2][0:3] = [st+1,st+2,st+9]

    cur = 1
    k = 0
    while n-k > 3:
        if (n-k) % 2:
            for j in range(n-k-1):
                ans[n-k-1][j] = cur
                cur += 1
            for i in reversed(range(n-k)):
                ans[i][n-k-1] = cur
                cur += 1
        else:
            for i in range(n-k):
                ans[i][n-k-1] = cur
                cur += 1
            for j in reversed(range(n-k-1)):
                ans[n-k-1][j] = cur
                cur += 1

        k += 1


    for row in ans:
        print(*row)

main()
