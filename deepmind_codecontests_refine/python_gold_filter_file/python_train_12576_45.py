n = int(input())
s = [input() for _ in range(n)]

a = 0
b = 0
ab = 0
c = 0

for i in range(n):
  if s[i][0:1] == 'B':
    b += 1
  if s[i][-1:] == 'A':
    a += 1
  if s[i][0:1] == 'B' and s[i][-1:] == 'A':
    ab += 1

  c += s[i].count('AB')

c2 = min(min(a, b), n-1)

if ab == a and ab == b and ab < n and c2 > 0:
  c2 -= 1

print(c+c2)
