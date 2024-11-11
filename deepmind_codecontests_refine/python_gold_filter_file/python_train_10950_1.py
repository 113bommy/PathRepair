from collections import deque
q = deque()
n,k = map(int,input().split())
l = 0
s = set()
for i in map(int,input().split()):
    if i not in s:
        if l==k:
            s.discard(q.popleft())
        else:
            l+=1
        q.append(i)
        s.add(i)

print(l)
print(*list(q)[::-1])