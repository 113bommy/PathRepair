(n, m) = [int(i) for i in input().split()]

maxnodes = 0
maxedges = 0
while maxedges < m:
    maxedges += maxnodes
    maxnodes += 1

mx = n - maxnodes
mn = max(n - 2 * m, 0)

print(mn, mx)
