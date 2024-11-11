n,k = map(int, input().split())
lag = []
for l in range(n):
    lag.append(int(input()))
w_max = 100000*100000
w_min = 0
while w_min < w_max:
    w_mid = (w_max + w_min) // 2
    tracks = 0
    current = 0
    for i in range(n):
        if lag[i] > w_mid:
            tracks = k
            break
        elif lag[i] + current > w_mid:
            tracks += 1
            current = lag[i]
        else:
            current += lag[i]
    if tracks < k:
        w_max = w_mid
    else:
        w_min = w_mid + 1
print(w_max)