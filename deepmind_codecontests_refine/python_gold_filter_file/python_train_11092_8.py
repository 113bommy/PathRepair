n = int(input())
s = input()
a = list(map(int, input().split()))
ans = 10000000000000
for i in range(n - 1):
    if s[i] == 'R' and s[i + 1] == 'L':
        ans = min(ans, (a[i + 1] - a[i]) // 2)
if ans == 10000000000000:
    print(-1)
else:
    print(ans)