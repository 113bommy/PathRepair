s = input()
n = len(s)
for i in range(n - 9):
    for j in range(n - i + 1):
        if s[:j] + s[j + i:] == 'CODEFORCES':
            print('YES')
            exit()
print('NO')
