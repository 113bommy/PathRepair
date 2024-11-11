n = int(input())
R = [int(input()) for _ in range(n)]
minv, maxv = R[0], R[1]-R[0]
for j in range(1, n):
    maxv = max(maxv, R[j]-minv)
    minv = min(minv, R[j])
print(maxv)