import heapq as hq
seq = []

n = int(input())
for i in range(n):
    [l, r] = [int(x) for x in input().split()]
    seq.append((l, -r, i+1))

seq.sort()

ans = (-1, -1)
for i in range(n-1):
    if seq[i][1] <= seq[i+1][1]:
        ans = (seq[i+1][2], seq[i][2])
        break
print(ans[0], ans[1])