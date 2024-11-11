INF = 10 ** 10

N = int(input())
 
L = [tuple(map(int,input().split())) for _ in range(N)]
 
L.sort(key=lambda x:(-x[0], x[1]))
 
MAX_L = 0
MIN_R = INF
MAX = 0
a = 0
b = 0
 
for i in range(N):
    if MAX_L < L[i][0]:
        MAX_L = L[i][0]
        a = i
    if MIN_R > L[i][1]:
        MIN_R = L[i][1]
        b = i
    MAX = max(MAX, L[i][1] - L[i][0] + 1)
 
ans = MAX + max(0, MIN_R - MAX_L + 1)
 
p = INF
 
for i in range(N-1):
    p = min(p, L[i][1])
    ans = max(ans, max(0, p - L[a][0] + 1) + max(0, L[b][1] - L[i+1][0] + 1))
 
print(ans)