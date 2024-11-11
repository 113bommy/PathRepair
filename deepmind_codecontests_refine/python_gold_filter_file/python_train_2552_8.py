n = int(input())
a = sorted(map(int, input().split()))
b = [0] * n
b[n - 1] = a[n - 1]
for i in range(n - 2, -1, -1):
    b[i] = max(0, min(b[i + 1] - 1, a[i]))
ans = sum(b)
print(ans)
