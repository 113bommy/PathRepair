from collections import deque

n = int(input())
a = list(map(int, input().split()))

b = deque([])
rev = 1
for i in a:
    if rev == 1:
        b.append(i)
        rev = -1
    elif rev == -1:
        b.appendleft(i)
        rev = 1

print(*(b if rev == 1 else list(b)[::-1]))
