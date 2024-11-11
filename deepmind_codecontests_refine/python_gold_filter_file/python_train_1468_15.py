vowel, s = 'aoieu', input()
if s[-1] != 'n' and s[-1] not in vowel:
    print('NO')
    exit()
for i in range(len(s) - 1):
    if s[i] != 'n' and s[i] not in vowel and s[i + 1] not in vowel:
        print('NO')
        exit()
print('YES')
