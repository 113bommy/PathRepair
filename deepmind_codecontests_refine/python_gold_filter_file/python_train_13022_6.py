n, m = map(int, input().split())
l = {i for i in range(1, m + 1)}
for i in range(n):
    a, b = map(int, input().split())
    l -= {i for i in range(a, b + 1)}
print(len(l))
print(*l)
