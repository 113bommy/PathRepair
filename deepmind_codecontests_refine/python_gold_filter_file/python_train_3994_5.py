n, k = map(int, input().split())
arr = list(map(int, input().split()))

if k == 1:
    print(1, 1)
    exit(0)

def find(ids):
    map = dict()
    count = 0
    for i in ids:
        if arr[i] not in map:
            count = count + 1

        map[arr[i]] = True

        if count == k:
            return i + 1

    return -1


right = find(range(0, len(arr)))

if right == -1:
    print(-1, -1)
    exit(0)

left = find(range(right-1, -1, -1))
print(left, right)
