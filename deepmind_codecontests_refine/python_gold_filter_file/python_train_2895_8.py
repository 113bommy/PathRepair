s = input()
t = s[::2].count('0') + s[1::2].count('1')
print(min(t, len(s)-t))