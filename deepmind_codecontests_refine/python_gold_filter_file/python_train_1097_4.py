from sys import stdin, exit
n = int(stdin.readline().rstrip())
x = y = z = 0

for line in stdin.readlines():
    tx, ty, tz = map(int, line.rstrip().split(' '))
    x += tx; y += ty; z += tz
    
if x != 0 or y != 0 or z != 0:
    print('NO')
else:
    print('YES')