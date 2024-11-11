def gcd(a, b):
    if not b:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

t, w, b = [int(x) for x in input().split()]
c = lcm(w, b)
cnt = int(min(w, b) * (t // c))  
r = t % c
if r >= min(w, b):
    r = min(w, b) - 1
cnt += r
q = gcd(cnt, t)
print ('%d/%d' % (int(cnt // q), int(t // q)))
