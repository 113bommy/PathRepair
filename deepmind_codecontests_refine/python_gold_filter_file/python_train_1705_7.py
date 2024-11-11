n, m = map(int, input().split())
k = min(n, m) + 1
print(k)
for i in range(k):
    print(i, k - i - 1)