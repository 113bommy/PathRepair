smth = int(input())
for _ in range(smth):
    __, k = map(int, input().split())
    row = list(map(int, input().split()))
    maxim = max(row)
    minim = min(row)
    if maxim-minim > 2*k:
        print(-1)
    else:
        print(minim+k)