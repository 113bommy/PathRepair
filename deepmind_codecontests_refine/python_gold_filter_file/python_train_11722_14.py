n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

ans = 0
for i in range(n):
    ans += a[i]*min(min(k, n-k+1), min(i, n-i-1)+1)

print(ans/(n-k+1))
