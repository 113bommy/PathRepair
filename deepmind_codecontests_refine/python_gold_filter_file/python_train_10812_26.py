s = list(input())
k = int(input())
z_asc = ord('z')
for i in range(len(s)):
    tmp = ord(s[i])
    if 1 + z_asc - tmp <= k and s[i] != 'a':
        k -= 1 + z_asc - tmp
        s[i] = 'a'
if k % 26 != 0:
    s[-1] = chr(ord(s[-1]) + k%26)
ans = "".join(s)
print(ans)
