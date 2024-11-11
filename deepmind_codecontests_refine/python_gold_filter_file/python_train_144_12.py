n, c = map(int, input().split())
x = list(map(int, input().split()))
max_dif = 0
for i in range(1, n):
    if x[i - 1] - x[i] > max_dif:
        max_dif = x[i - 1] - x[i]
print(max(max_dif - c, 0))
