h, n = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(n)]
MOD = 10 ** 18
D = [MOD] * (h + 10 ** 4)
D[0] = 0
 
for i in range(h):
    for a, b in AB:
        D[i + a] = min(D[i + a], D[i] + b)
print(min(D[h:]))