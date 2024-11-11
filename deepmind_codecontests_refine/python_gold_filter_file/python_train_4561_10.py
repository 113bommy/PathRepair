s = input().replace("BC", "D")
ans = 0
a = 0
for i in range(len(s)):
    if s[i] == "A":
        a += 1
    elif s[i] == "D":
        ans += a
    else:
        a = 0
print(ans)