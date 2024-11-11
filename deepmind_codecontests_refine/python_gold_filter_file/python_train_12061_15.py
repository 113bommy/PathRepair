import collections
N, W = map(int, input().split())
wv = collections.defaultdict(list)
w = 0
for i in range(N):
    a, b = map(int, input().split())
    wv[a].append(b)
    if i == 0:
        w = a
s = [[0]*(len(wv[w+i])+1) for i in range(4)]

for i in range(4):
    wv[w + i].sort(reverse=True)
    for j, x in enumerate(wv[w + i]):
        s[i][j+1] = s[i][j] + x
ans = 0
L = len(wv[w+3])
for i in range(min(len(wv[w]), N)+1):
    tmp1 = s[0][i]
    weight1 = w * i
    if weight1 > W:
        break
    for j in range(min(len(wv[w+1])+1, N+1 - i)):

        tmp2 = tmp1 + s[1][j]
        weight2 = weight1 + (w+1)*j
        if weight2 > W:
            break
        for k in range(min(len(wv[w+2])+1, N+1 - i - j)):
            tmp3 = tmp2 + s[2][k]
            weight3 = weight2 + (w+2)*k
            if weight3 > W:
                break
            d = W - weight3

            ans = max(ans, tmp3 + s[3][min(L, d//(w+3))])
print(ans)
