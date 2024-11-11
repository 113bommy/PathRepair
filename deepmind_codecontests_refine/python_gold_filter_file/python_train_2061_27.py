s = input()
if 'L' in s[::2] or 'R' in s[1::2]:
    print('No')
else:
    print('Yes')