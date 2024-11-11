from math import *

n = int(input())
s = []
le = 0
ts = set()
for i in range(n):
    t = input()
    le = max(le, len(t))
    s.append(t)

al = list('abcdefghijklmnopqrstuvwxyz')
g = {}
for i in al:
    g[i] = set()
hc = False
#print(le)
for i in range(1, le + 1):
    for j in range(n):
        if hc:
            break
        for k in range(j + 1, n):
            if s[j][:i] == s[k][:i] and len(s[j]) > len(s[k]) == i:
                hc = True
                break
            else:
                try:
                    if s[j][:i-1] == s[k][:i-1] and s[j][i-1] != s[k][i-1]:
                        g[s[k][i-1]].add(s[j][i-1])
                except:
                    pass
    if hc:
        break
#for i in g:
#    print(i, g[i])
ans = []
d = {}
while len(ans) < 26:
    if hc:
        break
    for i in al:
        d[i] = 0
    for v in g:
        for u in g[v]:
            d[u] += 1
    c = 0
    for v in d:
        if d[v] == 0 and v not in ans:
            c += 1
            ans.append(v)
            g[v] = set()
    if c == 0:
        hc = True
        break
        
if hc:
    print('Impossible')
else:
    print(''.join(reversed(ans)))
