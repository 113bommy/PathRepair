s = input().split(' ')
a = [int(x) for x in s]

lest = abs(a[0]-a[1])*a[3]

lift = (abs(a[2] - a[0]) * a[4]) + (3 * a[5]) + (abs(a[0] - a[1]) *a[4])

print('YES' if lift <= lest else 'NO')
