n = int(input())

t = input()
v = input()

s = list(set(list(t)).union(set(list(v))))
uf = [i for i in range(len(s))]

def find(uf,i):
    p = uf[i]
    return p if i==p else find(uf,p)

def union(uf,i,j):
    uf[find(uf,i)] = find(uf,j)

res = []    
for i in range(n):
    ti = s.index(t[i])
    vi = s.index(v[i])
    if (find(uf,ti) != find(uf,vi)):
        union(uf,ti,vi)
        res.append((t[i],v[i]))

print(len(res))
for i in range(len(res)):
    print(res[i][0],res[i][1])