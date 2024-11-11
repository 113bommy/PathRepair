def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return [str(x) for x in stdin.readline().split()]


from sys import stdin
from math import ceil, floor

a, x, y = arr_inp(1)
ypos = ceil(y / a)
if (y % a == 0) or ((ypos & 1 == 0 or ypos == 1) and (abs(x) >= abs(a / 2))) or (
        (ypos & 1 and ypos > 1) and (abs(x) == 0 or abs(x) >= a)):
    exit(print('-1'))

if ypos & 1 == 0 and ypos > 3:
    ypos += floor((ypos - 1) / 2)
elif (ypos & 1) and ypos > 1:
    if ypos > 3:
        ypos += floor((ypos - 2) / 2)
    if x > 0:
        ypos += 1
print(ypos)
