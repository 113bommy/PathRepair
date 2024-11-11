s = input()
c = 0
if 'm' in s or 'w' in s:
    c = 0
else:
    n = len(s)
    mod = 1000000007
    a = [0] * (n+1)
    a[0] = 1
    a[1] = 1
    for i in range(2, n+1):
        a[i] = a[i-1]
        if(s[i-1] == s[i-2] and (s[i-1] == 'u' or s[i-1] == 'n')):
           a[i] = ((a[i - 1] + a[i-2]) % mod)
    c = a[n]
print(c)
