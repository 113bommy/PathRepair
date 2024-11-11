s = input()
t = 'CODEFORCES'
k = 0
for i in range(len(t)+1):
   if s.startswith(t[:i]) and s.endswith(t[i:]):
       print('YES')
       break
else:
    print('NO')