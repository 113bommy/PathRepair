import heapq

n = int(input())
A = list(map(int, input().split()))

pre = [0]*(n+1)
pre_list = [e for e in A[:n]]
heapq.heapify(pre_list)
pre_sum = sum(pre_list)
pre[0] = pre_sum
for i in range(n, 2*n):
    small = heapq.heappushpop(pre_list, A[i])
    pre_sum += A[i] - small
    pre[i-n+1] = pre_sum

suf = [0]*(n+1)
suf_list = [-e for e in A[2*n:]]
heapq.heapify(suf_list)
suf_sum = -sum(suf_list)
suf[-1] = suf_sum
for i in range(2*n-1, n-1, -1):
    large = -heapq.heappushpop(suf_list, -A[i])
    suf_sum += A[i] - large
    suf[i-n] = suf_sum

# print(pre)
# print(suf)

print(max([pre[i] - suf[i] for i in range(n+1)]))
