n, m, k, l = map(int, input().split())
x1 = (l + k - 1) // m + 1
if(x1 * m <= n and k + l <= n):
    print(x1)
else:
    print(-1)