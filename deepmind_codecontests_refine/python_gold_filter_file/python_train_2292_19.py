import heapq

N = int(input())
H = list(map(int, input().split()))
ans = []

a = [(-x, x) for x in H]
heapq.heapify(a)

for i in range(N):
    print(" {}".format(a[i][1]), end = "")
print()