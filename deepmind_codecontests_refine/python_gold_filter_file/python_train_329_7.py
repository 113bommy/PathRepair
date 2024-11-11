def extended_gcd(a, b):
    s, old_s = 0, 1
    r, old_r = b, a
    while r:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_s, s = s, old_s - q * s
    return old_r, old_s, (old_r - old_s * a) // b if b else 0
  
n, p, w, d = map(int, input().split())
g, x, y = extended_gcd(w, d)
if p % g != 0:
    print(-1)
    exit(0)

let = p // g
 
x *= let
y *= let
# print("here ",x, y)

x0 = d // g
y0 = w // g

# print(x, y)

klo = int(-1e20)
khi = int(1e20)

while klo <= khi:
    mid = (klo + khi) // 2
    if y - mid * y0 >= 0:
        klo = mid + 1
    else:
        khi = mid - 1
# print(klo-1)
x += (klo-1) * x0
y -= (klo-1) * y0
  
z = n - (x + y)
if x >= 0 and y >= 0 and z >= 0 and (x * w + y * d == p):
    print(x, y, z)
else:
    print(-1)