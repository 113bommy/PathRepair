import math
xy = []
for i in range(3):
    xy.append([int(item) for item in input().split()])
xy.append(xy[0])

dist = []
for i in range(3):
    distance = math.sqrt((xy[i][0] - xy[i+1][0])**2.0 + (xy[i][1] - xy[i+1][1])**2.0)
    dist.append([distance, i, (i+1) % 3, (i+2) % 3])
dist.sort(reverse=True)

def get_vector(a, b):
    v = [a[0] - b[0], a[1] - b[1]]
    return v

def norm(a):
    n = math.sqrt(a[0] * a[0] + a[1] * a[1])
    return n

a = get_vector(xy[dist[0][-1]], xy[dist[0][-2]])
b = get_vector(xy[dist[0][-3]], xy[dist[0][-2]])
c = get_vector(xy[dist[0][-1]], xy[dist[0][-3]])
d = get_vector(xy[dist[0][-2]], xy[dist[0][-3]])
bc = dist[0][0]

ctheta = (a[0] * b[0] + a[1] * b[1]) / (norm(a) * norm(b))
cphi = (c[0] * d[0] + c[1] * d[1]) / (norm(c) * norm(d))
htheta = (math.pi - math.acos(ctheta)) / 2.0
hphi = (math.pi - math.acos(cphi)) / 2.0
r = bc / (math.tan(htheta) + math.tan(hphi) + 2)
print(r)