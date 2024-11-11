n = int(input())
ans = 0
for _ in range(n):
    l = list(map(int, input().split()))
    if l.count(1) >= 2:
        ans += 1
print(ans)