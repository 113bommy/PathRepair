_ = input()
S = input().lstrip('.').rstrip('#')
n = len(S)

x = 0
y = S.count('.')
c = min(n-y, y)
for i in range(n):
  if S[i] == '#':
    x += 1
  else:
    y -= 1
  c = min(c, x+y)
print(c)