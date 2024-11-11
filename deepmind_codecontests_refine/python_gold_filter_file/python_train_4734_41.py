s = input()
s = s[:-1]
s = s.strip().lower()

if s[-1] in 'aeiouy':
    print('YES')
else:
    print('NO')
