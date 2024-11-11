from sys import stdin
n, q = map(int, input().split())
cnt = [0]*n
root = [[] for i in range(n)]

for i in range(n-1):
    a, b = map(int, stdin.readline().split())
    root[a-1].append(b-1)

for i in range(q):
    p, x = map(int, stdin.readline().split())
    cnt[p-1] += x

tmparr = [0]
while tmparr:
    tmpi = tmparr.pop()
    for i in root[tmpi]:
        cnt[i] += cnt[tmpi]
    tmparr += root[tmpi]
print(*cnt)