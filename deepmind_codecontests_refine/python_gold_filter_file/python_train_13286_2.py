n, k = map(int, input().split())
a = n * (n - 1) // 2
b = a * (n - 2) // 3
c = b * (n - 3) // 4
print(sum([1, 0, a, 2 * b, 9 * c][:k + 1]))