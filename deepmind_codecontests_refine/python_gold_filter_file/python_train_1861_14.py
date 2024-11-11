from math import cos, sin, pi

treasure_x, treasure_y = 0, 0
angle = pi / 2

while True:
    d, a = map(int, input().split(','))

    if d == 0 and a == 0:
        break

    treasure_x += d * cos(angle)
    treasure_y += d * sin(angle)

    angle -= a * pi / 180

print(int(treasure_x))
print(int(treasure_y))