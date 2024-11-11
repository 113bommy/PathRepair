s = input().strip()
t = input().strip()

f = [-1]*len(t)
l = [-1]*len(t)

i = 0
for j in range(len(s)):
    if s[j] == t[i]:
        f[i] = j
        i += 1
    if i == len(t):
        break

i = len(t)-1
for j in range(len(s)-1, -1, -1):
    if s[j] == t[i]:
        l[i] = j
        i -= 1
    if i < 0:
        break

ans = max(len(s)-f[-1]-1, l[0])
# print(len(s)-f[-1]-1, l[0])
# print(f, l)
for i in range(1, len(t)):
    ans = max(ans, l[i]-f[i-1]-1)
print(ans)
