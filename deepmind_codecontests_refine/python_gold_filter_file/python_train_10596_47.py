N, K = map(int, input().split())

m = 0

while K**m <= N:
    m += 1

print(m)
