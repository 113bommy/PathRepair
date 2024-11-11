# seishin.py
N, M = map(int, input().split())
D = [[] for i in range(M+1)]
for i in range(N):
    l, r = map(int, input().split())
    D[r-l+1].append(l)

data = [0]*(M+2)
def get(k):
    s = 0
    while k:
        s += data[k]
        k -= k & -k
    return s
def add(k, x):
    while k <= M+1:
        data[k] += x
        k += k & -k

C = N
ans = []
for d in range(1, M+1):
    for l in D[d]:
        add(l, 1)
        add(l+d, -1)
        C -= 1

    cnt = C
    i = d
    while i <= M:
        cnt += get(i)
        i += d
    ans.append(cnt)
print(*ans, sep='\n')
