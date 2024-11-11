a = input()
f = False
for i in range(len(a)):
    for t in range(i, len(a) + 1):
        if a[0 : i] + a[t : len(a)] == 'CODEFORCES':
            f = True
            break
if f:
    print('YES')
else:
    print('NO')
    
