import heapq

n = int(input())
a = list(map(int, input().split()))

red, blue = a[:n], [-1*i for i in a[2*n:]]
sr, sb = sum(red), sum(blue)

results = [0] * (n + 1)
results[0] = sr
results[-1] = sb

heapq.heapify(red)
heapq.heapify(blue)

for k in range(n, 2*n):
    v = a[k]
    p = heapq.heappushpop(red, v)
    sr += v - p
    results[k-n+1] += sr

for k in range(2*n-1, n-1, -1):
    v = -1 * a[k]
    p = heapq.heappushpop(blue, v)
    sb += v - p
    results[k-n] += sb

print(max(results))
