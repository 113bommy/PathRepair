from math import log
x, y = map(int, input().split())

if x * log(y) == y * log(x):
    print('=')
elif x * log(y) > y * log(x):
    print('<')
else:
    print('>')
