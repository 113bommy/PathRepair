n = int(input())
data = [0] * n
for _ in range(n):
    a, v = [int(el) for el in input().split()]
    data[a-1] += v
result = max(data)
print(data.index(result)+1, result)