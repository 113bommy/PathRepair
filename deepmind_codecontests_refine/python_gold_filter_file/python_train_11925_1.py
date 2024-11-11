n, m = [int(x) for x in input().split()]

x = 7
d1 = 1
while x<n:
    d1 += 1
    x *= 7

x = 7
d2 = 1
while x<m:
    d2 += 1
    x *= 7

if d1 + d2 > 7:
    print(0)
    exit()
    
c1 = {}
L = [0]*d1
L[0] = -1
for sadas in range(n):
    L[0] += 1
    for j in range(d1):
        if(L[j] == 7):
            L[j] = 0
            L[j+1] += 1
    g = [0]*7
    for j in range(7):
        g[j] = len([x for x in L if x==j])
    if max(g)<2:
        if tuple(g) not in c1:
            c1[tuple(g)] = 0
        c1[tuple(g)] += 1

c2 = {}
L = [0]*d2
L[0] = -1
for sadas in range(m):
    L[0] += 1
    for j in range(d2):
        if(L[j] == 7):
            L[j] = 0
            L[j+1] += 1
    g = [0]*7
    for j in range(7):
        g[j] = len([x for x in L if x==j])
    if max(g)<2:
        if tuple(g) not in c2:
            c2[tuple(g)] = 0
        c2[tuple(g)] += 1

ans = 0
for x in c1:
    for y in c2:
        if len([z for z in range(7) if x[z]+y[z]>1])==0:
            ans += c1[x]*c2[y]
print(ans)
