n = int(input())
a = list(map(int, input().split()))
res = {}
for i in range(n):
    res[a[i] - i] = res.get(a[i] - i, 0) + a[i]
print(max(res.items(), key=lambda x: x[1])[1])
