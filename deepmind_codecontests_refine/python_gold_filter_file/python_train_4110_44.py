temp = [int(x) for x in input().split()]
a = temp[0]
b = temp[1]
c = temp[2]
d = temp[3]
x = max(3*a//10, a-a//250*c)
y = max(3*b//10, b-b//250*d)
if x > y:
    print('Misha')
elif x == y:
    print('Tie')
else:
    print('Vasya')
