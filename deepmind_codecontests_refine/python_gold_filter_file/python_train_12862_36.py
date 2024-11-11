n = int(input())
x = []
ans = ''
for i in range(n):
    s = input()
    if ans != 'YES' and s.count('OO') > 0:
        s = s.replace('OO','++',1)
        ans = 'YES'
    x.append(s)

if ans == 'YES':
    print(ans)
    for i in x:
        print(i)
else:
    print('NO')

