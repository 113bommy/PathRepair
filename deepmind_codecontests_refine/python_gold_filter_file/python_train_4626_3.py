n = int(input())
lst = [1] * 100
a, b = [int(k) for k in input().split()]
for i in range(n - 1):
    x, y = [int(z) for z in input().split()]
    for j in range(x, y):
        lst[j] = 0
print(sum(lst[a: b]))
