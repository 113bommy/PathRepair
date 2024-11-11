n, m = map(int, input().split())
ans = []
idx = 0
for _ in range(n):
    x = list(map(int, input().split()))
    for i in range(x[0]):
        if x[i+1] < m:
            idx += 1
            ans.append(_+1)
            break
print(idx)
print(*sorted(ans), sep=' ')