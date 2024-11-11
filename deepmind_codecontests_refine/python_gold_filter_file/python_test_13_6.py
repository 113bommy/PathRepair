n = int(input())
for _ in range(n):
    s = input()
    ac = bc = cc = 0
    for ele in s:
        if ele == 'A':
            ac += 1
        elif ele == 'B':
            bc += 1
        else:
            cc += 1
    if bc == (ac + cc):
        print('YES')
    else:
        print('NO')