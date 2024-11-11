n = int(input())
s = list(input())
if s.count('1') != s.count('0'):
    print(1)
    print(''.join(s))
else:
    print(2)
    print(''.join(s[:-1]), s[-1])