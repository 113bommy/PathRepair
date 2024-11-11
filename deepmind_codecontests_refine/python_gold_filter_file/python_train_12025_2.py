n = int(input())
p = []
a = []
ans = 0
for j in range(n):
    c, b = map(int, input().split())
    p.append(b)
    a.append(c)
price = p[0]
for i in range(n):
    if p[i] < price:
        price = p[i]
    ans += a[i] * price
print(ans)
