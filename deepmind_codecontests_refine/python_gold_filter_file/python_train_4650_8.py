import heapq

[n, k1, k2] = [int(x) for x in input().split(" ")]

A = input().split(" ")
B = input().split(" ")
error = 0
diff = [0] * n
for i in range(n):
    a = int(A[i])
    b = int(B[i])
    diff[i] = -1 * abs(a - b)
heapq.heapify(diff)

k = k1 + k2
error = 0
for i in range(k):
    tmp = heapq.heappop(diff)
    if tmp == 0 and i != k - 1:
        error = 0 if (k - i) % 2 == 0 else 1
        break
    heapq.heappush(diff, tmp + 1)

for i in diff:
    error = error + i * i
print(error)
