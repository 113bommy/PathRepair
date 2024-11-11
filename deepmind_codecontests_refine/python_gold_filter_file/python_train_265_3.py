n = int(input())
s = input()
a = ['a', 'e', 'i', 'o', 'u', 'y']
b = ['e', 'o']
s += '-'
ans = ''
c = 1
for i in range(0, len(s) - 1):
    if s[i] == s[i + 1]:
        c += 1
    else:
        if s[i] in b:
            if c == 2:
                ans += s[i] * 2
            else:
                ans += s[i]
        elif s[i] in a:
            ans += s[i]
        else:
            ans += s[i] * c
        c = 1
print(ans)
