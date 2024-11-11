from math import sqrt

def sqr(a):
        return a * a

a, b, c = [float(i) for i in input().split()]
x1, y1, x2, y2 = [float(i) for i in input().split()]

if a == 0 or b == 0:
        print(abs(x1 - x2) + abs(y1 - y2))
        exit(0)

c1_y = -(a * x1 + c) / b
c2_y = -(a * x2 + c) / b
c1_x = -(b * y1 + c) / a
c2_x = -(b * y2 + c) / a

ans = abs(x1 - x2) + abs(y1 - y2)

now = abs(c1_y - y1) + sqrt(sqr(x1 - c2_x) + sqr(c1_y - y2)) + abs(c2_x - x2);
ans = min(ans, now);

now = abs(c1_y - y1) + sqrt(sqr(x1 - x2) + sqr(c1_y - c2_y)) + abs(c2_y - y2);
ans = min(ans, now);

now = abs(c1_x - x1) + sqrt(sqr(c1_x - c2_x) + sqr(y1 - y2)) + abs(c2_x - x2);
ans = min(ans, now);

now = abs(c1_x - x1) + sqrt(sqr(c1_x - x2) + sqr(y1 - c2_y)) + abs(c2_y - y2);
ans = min(ans, now);

print("%.30f" % ans)
