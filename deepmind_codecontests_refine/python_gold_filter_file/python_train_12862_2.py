n = int(input())
a = []
k = 0

for i in range(n):
    seat = input()
    if k == 0 and 'OO' in seat:
        a.append(seat.replace('OO', '++', 1))
        k = 1
    else:
        a.append(seat)

if k == 0:
    print('NO')
else:
    print('YES')
    for element in a:
        print(element)