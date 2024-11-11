n, m = map(int, input().split())

t = min(n, m)
print(t + 1)
for x in range(t + 1):
    print(x, t - x)
