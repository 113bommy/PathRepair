import sys
input = sys.stdin.readline
from collections import defaultdict, deque

n, k = map(int, input().split())
ids = list(map(int, input().split()))
flag = defaultdict(int)
q = deque([])

for id_i in ids:
    if flag[id_i] == 0:
        q.appendleft(id_i)
        flag[id_i] = 1
        
        if len(q) > k:
            remove_id = q.pop()
            flag[remove_id] = 0

print(len(q))
print(*q)