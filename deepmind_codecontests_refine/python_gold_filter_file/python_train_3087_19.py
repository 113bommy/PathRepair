input()
s = input().lower()
vowel = 'aeiouy'
ans = ''

last_is_vowel = False

for char in s:
    if char not in vowel:
        ans += char
        last_is_vowel = False
    elif not last_is_vowel:
        ans += char
        last_is_vowel = True

print(ans)
    
