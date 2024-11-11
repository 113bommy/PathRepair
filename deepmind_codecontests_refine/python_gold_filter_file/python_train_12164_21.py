n = int(input())
t = list(map(int, input().split()))
v = list(map(int, input().split()))
v.insert(0, 0)
v.append(0)
l = [0, 0]
r = [0]
for i in range(n):
    l.append(l[i+1]+t[i])
    r.append(l[i+2])
r.append(r[n])
d = 0
vl = 0
for k in range(l[n+1]*2):
    now = k / 2 + 0.5
    vr = 1000
    for i in range(n+2):
        tv = 0
        if now < l[i]:
            tv = v[i] + l[i] - now
        elif now < r[i]:
            tv = v[i]
        else:
            tv = v[i] + now - r[i]
        vr = min(vr, tv)
    d += (vl+vr) * 0.25
    vl = vr
print(d)