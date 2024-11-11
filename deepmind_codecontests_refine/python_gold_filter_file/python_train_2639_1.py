from math import pi, sqrt, acos, sin

def gcd(x, y):
    while abs(x) > 1e-4 and abs(y) > 1e-4:
        if x > y:
            x -= x // y * y
        else:
            y -= y // x * x
    return x + y
    
x1, y1 = map(float, input().split(' '))
x2, y2 = map(float, input().split(' '))
x3, y3 = map(float, input().split(' '))

s1 = sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2) 
s2 = sqrt((x1 - x3) ** 2 + (y1 - y3) ** 2)
s3 = sqrt((x2 - x3) ** 2 + (y2 - y3) ** 2)

angle1 = acos((s1 * s1 + s2 * s2 - s3 * s3) / (2 * s1 * s2))
angle2 = acos((s2 * s2 + s3 * s3 - s1 * s1) / (2 * s2 * s3))
angle3 = acos((s1 * s1 + s3 * s3 - s2 * s2) / (2 * s1 * s3))

N = pi / (gcd(angle1, gcd(angle2, angle3)))
p = 0.5 * (s1 + s2 + s3)
S = sqrt(p * (p - s1) * (p - s2) * (p - s3))
R = s1 * s2 * s3 / (4 * S)
S = 0.5 * N * R * R * sin(2 * pi / N)

print(S)