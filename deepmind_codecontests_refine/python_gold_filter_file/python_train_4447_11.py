def check(a):
    if(a <= h):
        return (a + 1) * a // 2  >= n
    else:
        kol = a - h + 1
        kol1 = (a - h + 1) // 2
        kol2 = kol - kol1
        return (h - 1) * h // 2 + (h + kol1 -1) * (h + kol1) // 2 - (h - 1) * h // 2 + (h + kol2 -1) * (h + kol2) // 2 - (h - 1) * h // 2 >= n

n, h = map(int, input().split())
l = 0
r = n
while(l + 1 < r):
    m = (l + r) // 2
    if(check(m)):
        r = m
    else:
        l = m
print(r)