n = int(input())
h = list(map(int, input().split()))
idx, size = 0, 0
for j in range(1,len(h)):
    if h[j-1] < h[j]:
        idx = j
    size = max(size,j-idx)
print(size)