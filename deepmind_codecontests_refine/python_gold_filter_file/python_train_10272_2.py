def extended_gcd(a, b):
    r_last = a
    r = b
    s_last = 1
    s = 0
    t_last = 0
    t = 1
    while r:
        rr = r
        rr_last = r_last
        r = r_last % r
        r_last = rr

        ss = s
        s = s_last - rr_last // rr * s
        s_last = ss

        tt = t
        t = t_last - rr_last // rr * t
        t_last = tt
        
    return [r_last, s_last, t_last]

# returns d where a*d = 1 mod n
def mod_inverse(a, n):
    g, s, t = extended_gcd(a, n)
    # if g > 1: return "NO"
    print(a, n,s,t)
    return (s+n)%n


def CRT(a, b, m, n):
    # print(f"c = {a} mod {m}")
    # print(f"c = {b} mod {n}")
    g, p, q = extended_gcd(m, n)
    if (a - b) % g != 0: return "NO"
    lcm = m * n // g
    ans = a * n * q // g + b * m * p // g
    # print(d, e)
    return (ans+lcm)%lcm

# print(CRT(-1,-1,15,9))
# print(CRT(3, 1, 5, 3))
m, n, x, y, vx, vy = map(int, input().split(" "))
if (vx == 0 and (x % m) != 0) or (vy == 0 and (y % n) != 0) or (vx == 0 and vy == 0):
    print(-1)
    quit()

if vx == 0:
    yy = n if vy == 1 else 0
    print(x, yy)
    quit()

if vy == 0:
    xx = n if vx == 1 else 0
    print(xx, y)
    quit()

tar_x = x * (vx == 0) + m * (vx == 1)
tar_y = y * (vy == 0) + n * (vy == 1)

if tar_x - x == tar_y - y:
    print(tar_x, tar_y)
    quit()

c = CRT(-1 * x * vx, -1 * y * vy, m, n)
# print(c)
if c == "NO":
    print(-1)
else:
    first_bounce_x = x * (vx == -1) + (m - x) * (vx == 1)
    first_bounce_y = y * (vy == -1) + (n - y) * (vy == 1)
    first_bounce_dist = min(first_bounce_x, first_bounce_y)

    hor_bounces = ((c - first_bounce_dist) // m)
    vert_bounces = ((c - first_bounce_dist) // n)
    # print(hor_bounces, vert_bounces)
    hor_side =  hor_bounces % 2
    vert_side =  vert_bounces % 2

    h = v = -1
    # print(((c+x) // m -1*(x % m == 0)), ((c+y) // n -1*(y % n == 0)))
    # print(c, hor_side, vert_side)
    if hor_side == 0 and vx == -1: h = 0
    elif hor_side == 1 and vx == -1: h = 1
    elif hor_side == 0 and vx == 1: h = 1
    else: h = 0

    if vert_side == 0 and vy == -1: v = 0
    elif vert_side == 1 and vy == -1: v = 1
    elif vert_side == 0 and vy == 1: v = 1
    else: v = 0
    print(h * m, v * n)
    




    
    
    