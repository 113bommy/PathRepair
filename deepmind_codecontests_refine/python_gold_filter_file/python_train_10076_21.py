N = int(input())
P = list(map(int, input().split()))
m = N+1
ans = 0
for p in P:
    if p<=m:
        ans += 1
        m=p
print(ans)