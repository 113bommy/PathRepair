while True:
    try:
        a, b, c, d, e, f = map(float, input().split())
        z = a * e - b * d
        x = (c * e - b * f) / z
        y = (a * f - c * d) / z
        print("{:.3f} {:.3f}".format(x + 0, y + 0))
    except:
        break