n, m = [int(i) for i in input().split()]
max_sum = (n * (n - 1)) // 2
min_sum = ((n - 1) // 2 + 1) * ((n - 1) // 2) // 2 + (n - 1 - (n - 1) // 2 + 1) * (n - 1 - (n - 1) // 2) // 2
ans = 0
#print(n, max_sum, min_sum)
for i in range(m):
    data = [int(j) for j in input().split()]
    if data[1] > 0:
        wk1 = max_sum
    else:
        wk1 = min_sum
    ans += data[0] * n + data[1] * wk1

print(ans / n)