import sys
u, v = map(int, input().split())
if (u > v):
    print(-1)
    sys.exit(0)
if (u == v and u == 0):
    print(0)
    sys.exit(0)
if (u == v):
    print(1)
    print(u)
    sys.exit(0)
if ((v - u) % 2 == 1):
    print(-1)
    sys.exit(0)
ans = [0] * 64
ans[0] = u
v -= u
for i in range(65, -1, -1):
    if (u & (1 << i)):
        j = 63
        while ((1 << i) * (j - 1) > v):
            j -= 2
        v -= (1 << i) * (j - 1)
        for k in range(1, j):
            ans[k] += (1 << i)
    else:
        j = 64
        while ((1 << i) * j > v):
            j -= 2
        v -= (1 << i) * j
        for k in range(j):
            ans[k] += (1 << i)
if (v != 0):
    print(-1)
    sys.exit(0)
i = 0
answ = []
while(ans[i] != 0):
    answ.append(ans[i])
    i += 1
print(len(answ))
print(*answ)
