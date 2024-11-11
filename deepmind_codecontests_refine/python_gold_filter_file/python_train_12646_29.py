n = int(input())
z = input()
a = z.lower()
if len(set(a)) == 26:
    print('YES')
else:
    print('NO')
