import sys
t = int(input())
while t:
    s = list(map(int, sys.stdin.readline().split()))
    x, y, z = s[0], s[1], s[2]
    if x == y == z:
        print('YES')
        print(" ".join(list(map(str, s))))
        t -= 1
        continue
    elif max(x, y) == z:
        print('YES')
        m = min(x,y)
        print('1 ' + str(m)+' '+str(z))
    elif max(x,z) == y:
        print('YES')
        m = min(x,z)
        print('1 ' + str(m)+' ' + str(y))
    else:
        print('NO')
    t -= 1