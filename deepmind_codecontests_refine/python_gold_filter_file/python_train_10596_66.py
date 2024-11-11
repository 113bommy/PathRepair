N, K = map(int,input().split())
d = 0
while K**d <= N:
    d += 1
print(d)
