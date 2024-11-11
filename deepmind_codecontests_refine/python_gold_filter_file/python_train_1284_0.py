n, k, t = map(int, input().split())
l = (1 << (n + 1)) - 1

p = [tuple(map(int, input().split())) for i in range(k)]
p.sort(key = lambda i: i[2])
a, b = -1, sum(i[2] for i in p)

def g(j, s, u, v):
    global k, p, t
    k += 1
    if k > t: return
    for i, (h, w, r) in enumerate(p[j:], j + 1):
        if r > s: break
        if ((u >> h) & 1) and ((v >> w) & 1):
            g(i, s - r, u - (1 << h), v - (1 << w))
        
def f(s):
    global k, l
    k = 0
    g(0, s, l, l)
    return k
   
while b - a > 1:
    c = (a + b) // 2
    if f(c) < t: a = c
    else: b = c
    
print(b)