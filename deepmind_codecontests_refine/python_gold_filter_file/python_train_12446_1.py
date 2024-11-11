a1, b1, a2, b2, L, R = map(int, input().split())

def xgcd(a,b):
    prevx, x = 1, 0
    prevy, y = 0, 1
    while b:
        q = a // b
        x, prevx = prevx - q * x, x
        y, prevy = prevy - q * y, y
        a, b = b, a % b

    return a, prevx, prevy

g, x, y = xgcd(a1, -a2)

if (b2 - b1) // g < 0:    
    g, x, y = -g, -x, -y

if abs(b2 - b1) % abs(g) > 0:
    print(0)
else:
    a2g, a1g = a2 // abs(g), a1 // abs(g)

    x *= (b2 - b1) // g
    y *= (b2 - b1) // g

    if x < 0:
        y += ((abs(x) + a2g - 1) // a2g) * a1g
        x += ((abs(x) + a2g - 1) // a2g) * a2g      

    if y < 0:
        x += ((abs(y) + a1g - 1) // a1g) * a2g
        y += ((abs(y) + a1g - 1) // a1g) * a1g

    if x >= 0 and y >= 0:
        k = min(x // a2g, y // a1g)
        x -= k * a2g
        y -= k * a1g

    res = a1 * x + b1
    lcm = a1 * a2 // abs(g)

    L, R = max(0, L - res), R - res

    if R < 0:
        print(0)
    else:
        print(R // lcm - L // lcm + (L % lcm == 0))

