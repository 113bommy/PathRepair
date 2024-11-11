s = input().split('*')
ans = -1
for i in range(len(s)):
    for j in range(0, len(s)):
        copy = s[:i] + [str(eval('*'.join(s[i:i + j + 1])))] + s[i + j + 1:]
        ans = max(ans, eval('*'.join(copy)))
print(ans)