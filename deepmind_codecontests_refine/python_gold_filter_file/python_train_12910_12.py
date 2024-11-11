n,k = map(int, input().split())
w = [int(input()) for _ in range(n)]

def check(p):
    c = t = 0
    for wi in w:
        t += wi
        if t > p:
            t = wi
            c += 1
            if c >= k:
                return False
    return True

s = max(w)
l = sum(w)
while s < l:
    m = (s+l)//2
    if check(m):
        l = m
    else:
        s = m = m+1
print(s)