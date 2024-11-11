s = input()
length = len(s)
ans = '-1 -1'
for i in range(length - 1):
  if s[i] == s[i + 1]:
    ans = '{} {}'.format(i + 1, i + 2)
    break
  if i < length - 2 and s[i] == s[i + 2]:
    ans = '{} {}'.format(i + 1, i + 3)
    break
print(ans)