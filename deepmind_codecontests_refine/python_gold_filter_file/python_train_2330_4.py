
n, t = map(int, input().split())

a = list(map(int, input().split()))

prefix_sum = [0]

for i in range(n):
    prefix_sum.append(prefix_sum[i] + a[i])

x, y = 0, 1
ans = 0
n += 1
while y < n:
    if prefix_sum[y] - prefix_sum[x] <= t:
        if ans < y - x:
            ans = y - x
        y += 1
    else:
        x += 1

print(ans)