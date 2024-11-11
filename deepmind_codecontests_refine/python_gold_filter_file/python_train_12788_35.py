A,B,C,D,E,F = map(int,input().split())

ws = set()
for i in range(F+1):
    if 100*A*i > F: break
    for j in range(F+1):
        if 100*A*i + 100*B*j > F: break
        ws.add(100*A*i + 100*B*j)
ws.remove(0)
ss = set()
for i in range(F+1):
    if C*i > F: break
    for j in range(F+1):
        if C*i + D*j > F: break
        ss.add(C*i + D*j)

opt_w = 1
opt_s = -1
for w in ws:
    for s in ss:
        if w+s > F: continue
        if s*100 > w*E: continue
        if opt_s * (w+s) < s * (opt_w+opt_s):
            opt_w,opt_s = w,s
print(opt_w+opt_s, opt_s)