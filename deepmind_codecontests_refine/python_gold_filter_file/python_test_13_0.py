n = int(input())
for i in range(n):
    x = input()
    if x.count('A')+x.count('C') == x.count('B'):
        print('YES')
    else:
        print('NO')