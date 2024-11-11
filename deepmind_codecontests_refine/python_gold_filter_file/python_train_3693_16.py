def pal(a):
    n = len(a)
    for i in range(n // 2):
        if a[i] != a[n-1-i]:
            return False
    return True

s = input()
alp = 'abcdefghijklmnopqrstuvwxyz'
ans = 'NA'
for i in range(len(s) + 1):
    for j in alp:
        if pal(s[:i] + j + s[i:]):
            ans = s[:i] + j + s[i:]
            break
print(ans)