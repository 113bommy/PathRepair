mas = list(input().split('.'))
if len(mas) < 2:
    print('NO')
    exit(0)
    
if len(mas[0]) > 8 or len(mas[0]) < 1:
    print('NO')
    exit(0)

for i in range(1, len(mas) - 1):
    if len(mas[i]) > 11 or len(mas[i]) < 2:
        print('NO')
        exit(0)

if len(mas[len(mas) - 1]) > 3 or len(mas[len(mas) - 1]) < 1:
    print('NO')
    exit(0)
    
print('YES')
k = 0
z = 0
for i in range(1, len(mas) - 1):
    if len(mas[i]) == 11:
        print(mas[i - 1][k:]+'.'+mas[i][:3])
        k = 3
    elif len(mas[i]) == 10:
        print(mas[i - 1][k:]+'.'+mas[i][:2])
        k = 2
    elif len(mas[i]) == 9:
        print(mas[i - 1][k:]+'.'+mas[i][:1])
        k = 1
    else:
        print(mas[i - 1][k:]+'.'+mas[i][:1])
        k = 1
print(mas[len(mas) - 2][k:]+'.'+mas[len(mas) - 1])