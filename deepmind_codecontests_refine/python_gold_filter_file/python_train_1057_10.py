import sys
input = sys.stdin.readline
x, y, z = list(map(int, input().split()))
modx = x % z
mody = y % z
print((x + y) // z, end=' ')
if modx + mody >= z:
    print(z - max(modx, mody))
else:
    print('0')
