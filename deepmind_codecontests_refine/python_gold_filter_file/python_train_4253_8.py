from collections import deque

s = deque(input())

ans = 0
while len(s) > 1:
    if s[0] == s[-1]:
        s.pop()
        s.popleft()
    elif s[0] == 'x':
        s.popleft()
        ans += 1
    elif s[-1] == 'x':
        s.pop()
        ans += 1
    elif s[0] != s[-1]:
        print(-1)
        break
else:
    print(ans)
