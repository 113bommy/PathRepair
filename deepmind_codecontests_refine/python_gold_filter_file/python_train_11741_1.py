n = int(input())
ns = list(map(int, input().split()))
li = 1
ans = 0
max_leafs = [1]
for i in ns:
    li = (li - i) * 2
    max_leafs.append(li)
points = ns.pop()
ans += points
for i in range(len(ns)-1, -1, -1):
    a = ns[i]
    points = min(points + a, max_leafs[i])
    ans += points
if max_leafs[-1] < 0:
    print(-1)
else:
    print(ans)