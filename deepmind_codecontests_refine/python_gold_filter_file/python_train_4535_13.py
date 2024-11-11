n = int(input())
x = list(map(int, input().split()))
x.sort()
s = sum(x)
it = x[0]
m = s - n * x[0]
result = x[0]
for i in range(1, n):
    cur = s - it - (n - i) * x[i] + (i * x[i] - it)
    it += x[i]
    if cur < m:
        result = x[i]
        m = cur
print(result)