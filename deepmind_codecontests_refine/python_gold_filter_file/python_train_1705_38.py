n, m = map(int, input().split())
x = min(n, m)
print(x + 1)
for i in range(x + 1):
    print(i, x - i)
