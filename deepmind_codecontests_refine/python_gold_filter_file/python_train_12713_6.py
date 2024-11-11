n, k = map(int, input().split())
print((8 * n + k - 1) // k + (5 * n + k - 1) // k + (2 * n + k - 1) // k)