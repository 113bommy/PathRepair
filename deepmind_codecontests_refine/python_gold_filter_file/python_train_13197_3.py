n = int(input())
a = sorted(list(map(int, input().split())), reverse = True)

ans = 0
for i in range(1, n):
    ans += a[i // 2]

print(ans)