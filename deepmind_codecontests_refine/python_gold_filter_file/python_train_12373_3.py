n = int(input())
s = [input() for i in range(n)]
ans = ''
for i in range(97,97+26):
    count=float("inf")
    for j in range(n):
        count=min(count,s[j].count(chr(i)))
    ans += chr(i)*count

print(ans)
