import math
n = int(input())
heap = [None] + list(map(int, input().split()))
for i, x in enumerate(heap):
    if i == 0:
        continue
    p = math.floor(i / 2)
    parent = ''
    if 1 <= p:
        parent = "parent key = {}, ".format(heap[p])
    left = i * 2
    l = ''
    if left <= n:
        l = 'left key = {}, '.format(heap[left])
    right = i * 2 + 1
    r = ''
    if right <= n:
        r = 'right key = {}, '.format(heap[right])

    ans = "node {i}: key = {key}, {parent}{l}{r}".format(i=i, key=x, parent=parent, l=l, r=r)
    print(ans)