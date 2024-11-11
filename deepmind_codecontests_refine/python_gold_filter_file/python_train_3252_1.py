from bisect import bisect
subst = [0, 2, 3, 1]
pows = [4**i for i in range(28)]

def nxt(x):
    temp = []
    while(x):
        temp.append(x % 4)
        x //= 4
    res = 0
    for v in temp[::-1]:
        res = res * 4 + subst[v]
    return res
    
def task(x):
    y = x - (x-1) % 3
    r = pows[bisect(pows, y) - 1]
    z = y - (y-r) // 3 * 2
    for _ in range(x-y):
        z = nxt(z)
    return z
    
for _ in range(int(input())):
    print(task(int(input())))