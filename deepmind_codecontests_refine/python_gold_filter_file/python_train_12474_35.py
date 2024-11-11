s, w =input(), int(input())
ans = ''
c = 0
while c < len(s):
    ans += s[c]
    c += w
print(ans)