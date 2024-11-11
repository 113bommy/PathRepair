r = 0
p = None
for c in input():
    if p == 1:
        p = None
        r += 1
    elif c == p:
        p = 1
    else:
        r += 1
        p = c
print(r)
