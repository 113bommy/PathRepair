#ALDS1_3-C Elementary data structures - Doubly Linked List
import collections
q = collections.deque()
cmds={"insert":lambda cmd: q.appendleft(cmd[1]),
      "delete":lambda cmd: q.remove(cmd[1]) if (q.count(cmd[1]) > 0) else "none",
      "deleteFirst":lambda cmd: q.popleft(),
      "deleteLast": lambda cmd: q.pop()
     }

n=int(input())
for i in range(n):
    cmd=input().split()
    cmds[cmd[0]](cmd)
print(*q)