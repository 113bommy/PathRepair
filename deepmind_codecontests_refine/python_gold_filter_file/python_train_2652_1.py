m,t,r = map(int, input().split())
w = list(map(int, input().split()))

if r > t:
    print(-1); exit();
    
candles = []
for i in range(m):
    ct = 0
    for c in candles:
        if w[i] - c <= t:
            ct += 1
    for k in range(r - ct):
        candles.append(w[i] - k - 1)
print(len(candles))