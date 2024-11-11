a = [i for i in input().strip('?').split()]
c = ['a', 'e', 'i', 'o', 'u', 'y']
if a[-1][-1].lower() in c:
    print('YES')
else:
    print('NO')
