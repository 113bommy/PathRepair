s = str(input())
ans = ""
vowel = ['A','E','U','I','O','Y']

for i in range(len(s)):
        if s[i].upper() not in vowel:
                ans += '.' + s[i].lower()

print(ans)
