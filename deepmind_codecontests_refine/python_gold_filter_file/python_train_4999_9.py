from collections import deque
import sys

n = int(sys.stdin.readline())
q = deque()

for i in range(n):
    command = sys.stdin.readline()[:-1]
    if command[0] == 'i':
        q.appendleft(command[7:])
    elif command[6] == ' ':
        try:
            q.remove(command[7:])
        except Exception as e:
            pass
    elif command[6] == 'F':
        q.popleft()
    else:
        q.pop()

print(' '.join(q))