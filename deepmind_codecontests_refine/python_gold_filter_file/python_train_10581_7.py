n, m = map(int, input().split())
k=10000
for _ in range(n):
    q, w = map(int, input().split())
    if q/w<k:
        k=q/w
print(k*m)