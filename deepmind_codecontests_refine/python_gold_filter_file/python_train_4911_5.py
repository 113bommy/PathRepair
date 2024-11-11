n = int(input())
a = [[-1 for i in range(2*n+1)] for j in range(n+1)]
for i in range(n+1): a[i][n] = i; a[n][i] = i
for i in range(n+1):
    k = i
    for j in range(i+1):
        a[i][n-j] = k
        a[i][n+j] = k
        k -= 1
ans = ""
for i in range(n+1):
    for j in range(n+i):
        if a[i][j] == -1: ans += "  "
        else: ans += str(a[i][j])+" "
    ans += (str(a[i][n+i]))
    ans += "\n"
for i in range(n-1,-1,-1):
    for j in range(n+i):
        if a[i][j] == -1: ans += "  "
        else: ans += str(a[i][j])+" "
    ans += str(a[i][n+i])
    ans += "\n"
print(ans)