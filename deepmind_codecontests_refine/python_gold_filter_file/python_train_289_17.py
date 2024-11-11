s=input()
s=list(s)
a=list('keyence')
for i in range(8):
    if s[:i]==a[:i] and s[i-7:]==a[i-7:]:
        print('YES')
        quit()
print('NO')