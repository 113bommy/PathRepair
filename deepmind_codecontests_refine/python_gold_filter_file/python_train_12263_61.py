s =int(input())
if s % 27 == 13 or s % 27 == 26:
    print(':(')
else:
    print((-s * 25 // 27) * (-1))