import heapq

n = int(input().strip())
a = list(map(int, input().split()))
pre = a[:n]
heapq.heapify(pre)
suf = list(map(lambda x: -x, a[(2 * n):]))
heapq.heapify(suf)
left = {}
right = {}
pre_sum = sum(pre)
suf_sum = -sum(suf)
left[n - 1] = pre_sum
right[2 * n] = suf_sum
for i in range(n, 2 * n):
    heapq.heappush(pre, a[i])
    pre_sum = pre_sum + a[i] - heapq.heappop(pre)
    left[i] = pre_sum
for i in range(2 * n - 1, n - 1, -1):
    heapq.heappush(suf, -a[i])
    suf_sum = suf_sum + a[i] + heapq.heappop(suf)
    right[i] = suf_sum
ans = -float('inf')
for i in range(n - 1, 2 * n):
    ans = max(ans, left[i] - right[i + 1])
print(ans)
