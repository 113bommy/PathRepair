S = input()
for i in range(7):
    if S[:i] + S[i-7:] == 'keyence':
        print('YES')
        exit()
print('NO')
