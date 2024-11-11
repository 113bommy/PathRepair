n, A = map(int, input().split())
c = list(map(int, input().split()))
d = {}
cntA = 0
B = -1
for i in range(n):
    if c[i] == A:
        cntA += 1
    elif c[i] in d:
        if d[c[i]] >= cntA:
            d[c[i]] += 1
        else:
            d.pop(c[i])
    elif cntA == 0:
        d[c[i]] = 1
for i in d:
    if d[i] >= cntA:
        B = i
        break
print(B)