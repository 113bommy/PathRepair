#E
from collections import deque
n = int(input())
matches = [list(a -1 for a in map(int,input().split()))
     for _ in range(n)]
q = deque(range(n))
depth = [0] * n
waiting = [-1] * n

while q:
    a = q.popleft()
    ma = matches[a]
    if not ma:
        continue
    # gyaku kara kanngaeteru
    b = ma.pop()
    if waiting[b] == a:
        depth[a] = depth[b] = max(depth[a],depth[b]) +1
        q.append(a)
        q.append(b)
    else:
        waiting[a] = b
if any(matches):
    print(-1)
else:
    print(max(depth))