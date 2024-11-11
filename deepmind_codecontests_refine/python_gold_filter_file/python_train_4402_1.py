n = int(input())
a = list(map(int, input().split()))

m = max(a)
b = 0
while (1<<b)<m:
    b+=1
now = [a]
x = 0
inv = 0
for i in reversed(range(b)):
    nxt = []
    zrs = ons = 0
    for arr in now:
        zeroes = []
        ones = []
        zr = 0
        on = 0
        for j in arr:
            if (1<<i)&j!=0:
                on+=len(zeroes)
                ones.append(j)
            else:
                zr+=len(ones)
                zeroes.append(j)
        if len(zeroes)>0:
            nxt.append(zeroes)
        if len(ones)>0:
            nxt.append(ones)
        zrs+=zr
        ons+=on
    inv+=min(zrs, ons)
    if ons<zrs:
        x+=1<<i
    now = nxt.copy()
#print(now)
print(inv, x)
