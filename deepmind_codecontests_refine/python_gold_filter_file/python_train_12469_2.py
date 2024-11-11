D = int(input())
c = list(map(int, input().split()))
s = [list(map(int, input().split())) for _ in range(D)]
t = [int(input()) for _ in range(D)]

v = 0
last = [-1 for _ in range(26)]

for d in range(D):
    last[t[d]-1] = d
    v += s[d][t[d]-1]
    for j in range(26):
        v -= c[j]*(d-last[j])
    print(v)
