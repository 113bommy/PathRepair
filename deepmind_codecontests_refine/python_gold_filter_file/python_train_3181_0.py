from collections import deque
def mini_in_window(A, n, k):
    d = deque()
    res = []
    for i in range(n):
        if i >= k and d[0] == i - k:
            d.popleft()
        while len(d) and A[d[-1]] >= A[i]:
            d.pop()
        d.append(i)
        if i >= k - 1:
            res.append(d[0])
    return res


def maxi_in_window(A, n, k):
    d = deque()
    res = []
    for i in range(n):
        if i >= k and d[0] == i - k:
            d.popleft()
        while len(d) and A[d[-1]] <= A[i]:
            d.pop()
        d.append(i)
        if i >= k - 1:
            res.append(d[0])
    return res


n, k = map(int, input().split())
A = list(map(int, input().split()))
l = 0
r = n + 1
maxans = 0
cntmax = []
while l + 1 < r:
    mid = (l + r) // 2
    if mid > maxans:
        cntnow = []
        mins = mini_in_window(A, n, mid)
        maxes = maxi_in_window(A, n, mid)
        for i in range(len(mins)):
            if A[maxes[i]] - A[mins[i]] <= k:
                cntnow.append((i + 1, mid + i))
        if cntnow:
            l = mid
            cntmax = cntnow[:]
        else:
            r = mid
print(l, len(cntmax))
for line in cntmax:
    print(' '.join(map(str, line)))