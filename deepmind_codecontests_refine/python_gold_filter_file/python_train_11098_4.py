fr, ls = input().split()
n = int(input())
n %= 4
if n == 1:
    if fr == '^':
        if ls == '>':
            print('cw')
        else:
            print('ccw')
    if fr == '>':
        if ls == '^':
            print('ccw')
        else:
            print('cw')
    if fr == 'v':
        if ls == '>':
            print('ccw')
        else:
            print('cw')
    if fr == '<':
        if ls == '^':
            print('cw')
        else:
            print('ccw')
    exit()
if n == 3:
    if fr == '^':
        if ls == '<':
            print('cw')
        else:
            print('ccw')
    if fr == '>':
        if ls == '^':
            print('cw')
        else:
            print('ccw')
    if fr == 'v':
        if ls == '>':
            print('cw')
        else:
            print('ccw')
    if fr == '<':
        if ls == '^':
            print('ccw')
        else:
            print('cw')
    exit()
print('undefined')