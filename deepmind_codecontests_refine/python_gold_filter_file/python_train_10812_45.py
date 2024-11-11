s = input()
k = int(input())
l = [(26 - (ord(c) - ord('a'))) % 26 for c in s]
for i in range(len(s) - 1):
    if k >= l[i]:
        k -= l[i]
        s = s[:i] + 'a' + s[i + 1 :]

k %= 26
s = s[:-1] + chr(ord('a') + (ord(s[-1]) - ord('a') + k) % 26)
print(s)
