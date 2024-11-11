n = int(input())
numbers = (sorted(int(x) for x in input().split()))

best_s = 10 ** 18 + 10

for start in range(n + 1):
    x_len = numbers[start + n - 1] - numbers[start]
    y_len = numbers[-1] - numbers[0]
    if start + n - 1 == 2 * n - 1:
        y_len = numbers[start - 1] - numbers[0]
    elif start == 0:
        y_len = numbers[-1] - numbers[n]
    best_s = min(best_s, x_len * y_len)

print(best_s)
