import sys
s = input()
s1 = input()
for i in range(len(s)):
    if s[i] == '|':
        break
a = s[:i]
b = s[i + 1:]
x = len(a)
y = len(b)
d = len(s1)
if (y + d - x) % 2 != 0:
    print('Impossible')
    sys.exit()
k = (y + d - x) // 2
if k < 0 or k > d:
    print('Impossible')
    sys.exit()
print(a + s1[:k], end ='')
print('|', end = '')
print(b + s1[k:])