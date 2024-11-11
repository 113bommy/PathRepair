n = int(input())
t = 1
s = 0
o = 0
y = 0
while s < n:
    y += 1
    s += t
    o += 1
    if o == 5:
        t *= 2
        o = 0
y1 = y
while y1 % 5 != 0:
    y1 -= 1
if y-y1 == 1:
    print('Sheldon')
elif y-y1 == 2:
    print('Leonard')
elif y-y1 == 3:
    print('Penny')
elif y-y1 == 4:
    print('Rajesh')
elif y-y1 == 0:
    print('Howard')
