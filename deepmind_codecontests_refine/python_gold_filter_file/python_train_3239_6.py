n, m = list(map(int, input().split()))


min_ans = max(0, n - m * 2)

if m == 0:
    print(n, n)
    exit()

for i in range(1, n + 1):
    if m <= i * (i - 1) // 2:
        print(min_ans, n-i)
        exit()

print(min_ans, 0)
