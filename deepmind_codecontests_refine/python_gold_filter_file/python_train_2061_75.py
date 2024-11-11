s=input()
print('No') if 'L' in s[::2] or 'R' in s[1::2] else print('Yes')