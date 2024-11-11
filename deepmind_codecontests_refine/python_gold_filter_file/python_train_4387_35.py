s = input()
T = input().split()

for t in T:
    if s[0] == t[0] or s[1] == t[1]:
        print('YES')
        exit()
print('NO')