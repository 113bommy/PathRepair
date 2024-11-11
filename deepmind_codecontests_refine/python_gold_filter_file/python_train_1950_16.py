import math
x, y = map(int, input().split())

if y*math.log10(x) > x*math.log10(y):
    print('>')
elif y*math.log10(x) < x*math.log10(y):
    print('<')
else:
    print('=')