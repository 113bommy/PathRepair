from collections import deque

s = deque(list(input()))

ans = 0
while len(s) > 1:
    l = s.popleft()
    r = s.pop()
    if l == r:
        continue
    elif l == 'x':
        ans += 1
        s.append(r)
    elif r == 'x':
        ans += 1
        s.appendleft(l)
    else:
        print(-1)
        exit()

print(ans)
        