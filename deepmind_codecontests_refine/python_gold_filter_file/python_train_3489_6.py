def cross_pr(a_):
    x1, y1, x2, y2 = a_[:]
    return x1 * y2 - x2 * y1


def vector(a_):
    x1, y1, x2, y2 = a_[:]
    return [x1 - x2, y1 - y2]


def dist(a_):
    x1, y1 = a_[:]
    return (x1 * x1 + y1 * y1) ** 0.5


n = int(input())
x = [[] for i in range(n)]
for i in range(n):
    x[i] = [int(i) for i in input().split()]
a = [[0] * 2 for i in range(n - 1)]
for i in range(1, n):
    a[i - 1][0] = dist(vector(x[i] + x[0]))
    a[i - 1][1] = i
a.sort()
ans = [0] * 3
ans[0] = 0
ans[1] = a[0][1]
now = 2 * 10 ** 21 + 1
v1 = vector(x[ans[0]] + x[ans[1]])
for i in range(n):
    v2 = vector(x[i] + x[ans[1]])
    if abs(cross_pr(v1 + v2)) > 0:
        if abs(cross_pr(v1 + v2)) < now:
            now = abs(cross_pr(v1 + v2))
            ans[2] = i

for i in range(3):
    ans[i] += 1
print(*ans)