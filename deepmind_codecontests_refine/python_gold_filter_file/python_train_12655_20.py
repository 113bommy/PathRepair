n, k = map(int, input().split())
b = list(map(int, input().split()))
res = 0
for i in range(1, n):
    t = k - b[i] - b[i-1]
    if t > 0:
        res += t
        b[i] += t

print(str(res) + '\n' + " ".join(map(str, b)))
