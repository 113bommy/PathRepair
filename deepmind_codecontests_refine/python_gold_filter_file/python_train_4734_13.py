a = input()
s = []
for i in range(len(a)):
    s.append(a[i])
for i in range(s.count(' ')):
    s.remove(' ')
for i in range(s.count('?')):
    s.remove('?')
if s[len(s)-1] == 'A' or s[len(s)-1] == ' E' or s[len(s)-1] == 'I' or s[len(s)-1] == 'O' or s[len(s)-1] == 'U' or s[len(s)-1] == 'Y':
    print('YES')
elif s[len(s)-1] == 'a' or s[len(s)-1] == 'e' or s[len(s)-1] == 'i' or s[len(s)-1] == 'o' or s[len(s)-1] == 'u' or s[len(s)-1] == 'y':
    print('YES')
else:
    print('NO')