from collections import deque

n, k = map(int, input().split())
arr = deque(list(map(int, input().split())))

major = arr.popleft()
cnt = 0

while cnt < min(k, n):
    item = arr.popleft()
    if item < major:
        arr.append(item)
        cnt += 1
    else:
        cnt = 1
        arr.append(major)
        major = item

print(major)
