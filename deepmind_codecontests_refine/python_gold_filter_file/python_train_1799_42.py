def inp():
    return int(input())
def linp():
    return list(map(int, input().split()))
def minp():
    return map(int, input().split())
for _ in range(inp()):
    x= inp()
    su = 0
    c = 0
    for i in range(1, x+1):
        s = pow(2, i) - 1
        s2 = (pow(s, 2) + s) // 2
        if su + s2 > x:
            break
        else:
            su += s2
            c += 1
    print(c)
