s = input()
n = len(s)
p = 'CODEFORCES'
f = False
for i in range(11):
    res = s[:i] + s[i + n - 10:]
    f = (res[:] == 'CODEFORCES')
    if f: break
    
print('YES' if f else 'NO')
    
    