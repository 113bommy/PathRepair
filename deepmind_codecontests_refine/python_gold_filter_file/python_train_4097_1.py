s = input()
m = [""]*len(s)
c = s[-1]
ans = ""
for x in range(len(s)-1, -1, -1):
  if s[x] > c:
    c = s[x]
  m[x] = c
for y in range(len(s)):
  if s[y] == m[y]:
    ans += s[y]
print(ans)