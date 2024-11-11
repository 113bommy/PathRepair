s = input()
l = len(s)
for i in range(l):
    for j in range(i, l):
        if s[:i] + s[j + 1:] == "CODEFORCES":
            print('YES')
            exit()
print('NO')