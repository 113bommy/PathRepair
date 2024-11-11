n, x, y = map(int, input().split())
ans = [0] * (n-1)
for i in range(1, n):
    for j in range(i+1, n+1):
        d = min(j-i, abs(x-i)+abs(j-y)+1)
        ans[d-1] += 1
print(*ans, sep='\n')