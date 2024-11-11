N, K = [int(_) for _ in input().split()]
TD = [[int(_) for _ in input().split()] for i in range(N)]
 
# print(TD)
 
xs = sorted(TD, key=lambda x:-x[1])
 
#print(xs)
 
baset = 0
ts = set()
ds = []
 
for t, d in xs[:K]:
    baset += d
    if not t in ts:
        ts.add(t)
    else:
        ds.append(d)
result = baset + len(ts)**2
r = result

for t, d in xs[K:]:
    if not ds:
        break
    if t not in ts:
        r += 2*len(ts) + 1
        r += d - ds.pop()
        ts.add(t)
        result = max(r,result)

print(result)