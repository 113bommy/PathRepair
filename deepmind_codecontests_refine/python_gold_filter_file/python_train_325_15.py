n, x, y = map(int, input().split())
s = input()
ans = 0
z = str(10 ** x + 10 ** y)
for i in range(1, len(z)):
    if s[n - i] != z[len(z) - i]:
        ans += 1
print(ans)
