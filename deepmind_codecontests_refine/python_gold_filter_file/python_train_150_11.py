n, t = int(input()), input()
for i in range(n - 4):
    if t[i] == '*':
        for d in range(1, (n - i + 3) // 4):
            if t[i + d] == t[i + 2 * d] == t[i + 3 * d] == t[i + 4 * d] == '*':
                print('yes')
                exit()
print('no')