import string
alphabet = string.ascii_lowercase

s = [x for x in list(input().lower()) if x in alphabet]
if s[-1] in ['a', 'e', 'i', 'o', 'u', 'y']:
    print('YES')
else:
    print('NO')


