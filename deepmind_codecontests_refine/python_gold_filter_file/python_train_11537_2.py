import bisect

a, b, q = map(int, input().split())
INF = float('inf')
s = [-INF] + [int(input()) for _ in range(a)] + [INF]
t = [-INF] + [int(input()) for _ in range(b)] + [INF]
x = [int(input()) for _ in range(q)]

for i in x:
    si = bisect.bisect_left(s, i)
    ti = bisect.bisect_left(t, i)
    sl, sr = i-s[si-1], s[si]-i
    tl, tr = i-t[ti-1], t[ti]-i
    print(min(max(sl,tl), sl+tr+min(sl,tr), sr+tl+min(sr,tl), max(sr,tr)))