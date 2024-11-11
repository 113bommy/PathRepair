import sys
from collections import deque
readline = sys.stdin.readline
dq = deque()
for _ in range(int(input())):
    ss = readline().strip()
    if ss == "deleteFirst":
        del dq[0]
    elif ss == "deleteLast":
        del dq[-1]
    else:
        c, s = ss.split()
        s = int(s)
        if c == "insert":
            dq.appendleft(s)
        elif c == "delete":
            if s in dq:
                dq.remove(s)
print(*dq)

