s = input()
a = s[::2].count('0') + s[1::2].count('1')
print(min(a, len(s)-a))
