n = int(input())
ans = 0
for _ in range(n):
    if sum([int(i) for i in input().split()]) >= 2:
        ans += 1
print(ans)