n, c = map(int, input().split())
x = list(map(int, input().split()))
ans = 1
for i in range(1, n):
    if x[i] - x[i - 1] > c:
        ans = 1
    else:
        ans += 1
print(ans)
