n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d = {}
res = [0] * (n + 1)
for i in range(n):
    d[a[i]] = [i]
# print(d)
for i in range(n):
    d[b[i]].append(i)
# print(d)
for i in range(n):
    l, h = d[a[i]]
    if (h > l):
        res[h - l] += 1
    else:
        res[n - l + h] += 1
# print(res)
print(max(res))
