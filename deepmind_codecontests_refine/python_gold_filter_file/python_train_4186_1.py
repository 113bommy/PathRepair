import math
q = int(input())
while q > 0:
    n = int(input())
    s = input()
    L = []
    for i in range(len(s)):
        L.append(s[i])
    if '1' not in L:
        print(n)
    else:
        a1 = L.index('1')
        L.reverse()
        a2 = L.index('1')
        d = min(a1,a2)
        print((n - d) * 2)
    q -= 1
