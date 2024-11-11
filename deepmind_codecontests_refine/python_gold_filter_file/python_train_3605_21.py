q = int(input())
w = list(map(int, input().split()))
e = list(map(int, input().split()))
z = -1
r = max(e)
for i in range(q):
    if e[i] == r:
        z = i
del(e[z])
k = max(e)
if k + r < sum(w):
    print('NO')
else:
    print('YES')
