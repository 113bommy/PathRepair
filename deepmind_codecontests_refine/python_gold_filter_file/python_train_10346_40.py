n, k = map(int, input().split())
max = -1000000000
for _ in range(n):
    f, t = map(int, input().split())
    if t > k:
        f = f - (t - k)
        if max < f:
            max = f
    else:
        if max < f:
            max = f
            
print(max)