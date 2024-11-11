s = input()
d = {}
k = 1
for i in range(ord('a'), ord('z') + 1):
    d[chr(i)] = k
    k += 1
if (s[0] != 'a'):
    count = min(d[s[0]] - 1, 27 - d[s[0]])
else:
    count = 0
for i in range(1, len(s)):
    count += min(abs(ord(s[i - 1]) - ord(s[i])),
                 26 - abs(ord(s[i - 1]) - ord(s[i])))
print(count)
