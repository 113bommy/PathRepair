a = list(input())
b = list(input())
x1 = a[0]
y1 = a[1]
x2 = b[0]
y2 = b[1]
(x1, y1, x2, y2) = map(ord, (x1, y1, x2, y2))

d = max(abs(x1 - x2), abs(y1 - y2))
e = min(abs(x1 - x2), abs(y1 - y2))
print(d)

mx = ''
my = ''
if x1 < x2:
    mx = 'R'
else:
    mx = 'L'
if y1 < y2:
    my = 'U'
else:
    my = 'D'
for i in range(0, e):
    print(mx + my)
p = mx
if abs(x1 - x2) < abs(y1 - y2):
    p = my
for i in range(0, d - e):
    print(p)

