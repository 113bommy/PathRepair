n = int(input())
s = input()
m = s.count(".")
ans = m

for i in range(n):
    if s[i] == "#":
        m += 1
    else:
        m -= 1
    ans = min(ans, m)
print(ans)