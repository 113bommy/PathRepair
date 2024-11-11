s = input()

ss = input().split()

for i in ss:
    if s[0] == i[0] or s[1] == i[1]:
        print('YES')
        exit()
print('NO')