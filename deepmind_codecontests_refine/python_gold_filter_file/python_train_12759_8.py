s = list(input()+'a')
if s == ['a']*len(s): print('a'*(len(s)-2)+'z'); exit()
for i in range(len(s)):
    if s[i] != 'a': break
for j in range(i+1, len(s)):
    if s[j] == 'a': break
for k in range(i, j):
    s[k] = chr(ord(s[k])-1)
print(''.join(s)[:-1])

