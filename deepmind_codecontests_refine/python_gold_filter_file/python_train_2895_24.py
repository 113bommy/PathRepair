s = input()
c1 = s[::2].count('0') + s[1::2].count('1')
c2 = s[::2].count('1') + s[1::2].count('0')
print(min(c1, c2))