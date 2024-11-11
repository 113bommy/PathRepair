n = int(input())
s = input()

ans = 0
i = j= 0

while j <= n-1:
    if s[i:j] in s[j:]:
        ans = max(ans, j-i)
        j += 1
    else:
        i += 1
print(ans)