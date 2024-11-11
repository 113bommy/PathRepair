n, w = map(int, input().split())
l1 = [list(map(int, input().split())) for i in range(n)]
v = 0
for i in range(n):
  v += l1[i][1]
d = [10 ** 9 + 1] * (v + 1)
d[0] = 0
for i in range(n):
    for j in range(v, -1, -1):
        d[j] = min(d[j], d[j - l1[i][1]] + l1[i][0])
answer = 0
for j in range(v + 1):
    if  w >= d[j]:
        answer = max(answer, j)
print(answer)