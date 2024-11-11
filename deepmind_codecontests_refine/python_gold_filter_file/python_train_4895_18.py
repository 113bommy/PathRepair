N = int(input())
R = [int(input()) for _ in range(N) ]

maxv = -2000000000
minv = R[0]

for r in R[1:]:

    maxv = max(maxv, r - minv)
    minv = min(minv, r)

print(maxv)

