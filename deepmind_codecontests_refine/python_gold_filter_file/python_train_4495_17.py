x = input().lower()
for i in x:
    if i not in ['a', 'e', 'i', 'o', 'u', 'y']:
        print('.' + i, end='')
