t = int(input())
for _ in range(t):
    s = input()
    if len(s) & 1 or s.count('B') != len(s) // 2:
        print('NO')
    else:
        print('YES')