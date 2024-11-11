n,a,b = map(int,input().split())
vs = sorted([int(v) for v in input().split()],reverse=True)
print(sum(vs[:a])/a)
binom = [1]
for k in range(vs.count(vs[a-1])):
    binom = [x+y for (x, y) in zip(binom+[0],[0]+binom)]
if vs[a-1] == vs[0]:
    print(sum(binom[a:b+1]))
else:
    print(binom[a-vs.index(vs[a-1])])