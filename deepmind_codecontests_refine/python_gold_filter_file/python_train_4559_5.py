(A, B, M), aa, bb, *xyc = [list(map(int, s.split())) for s in open(0)]

ans = min(aa)+min(bb)

for x, y, c in xyc:
    ans = min(ans, aa[x-1]+bb[y-1]-c)

print(ans)	