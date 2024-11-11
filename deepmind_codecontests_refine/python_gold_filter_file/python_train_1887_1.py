from collections import Counter

n = int(input())
a = sorted(Counter(map(int, input().split(' '))).values(), reverse=True)

res, k = a[0], a[0]

for i in range(1, min(len(a), 30)):
    k = min(k // 2, a[i - 1] // 2, a[i])
    res = max(res, k * (pow(2, i + 1) - 1))

print(res)
