n = int(input())
s = input()
ans = n
for i in range(n // 2 + 1):
    if s[:i] == s[i:2*i]:
        ans = min(ans, n - i + 1)
print(ans)
