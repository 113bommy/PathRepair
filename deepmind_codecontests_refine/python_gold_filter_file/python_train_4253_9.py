from collections import deque
s = deque(input())
le = len(s)
cnt = 0
while le>1:
  if s[0] == s[-1]:
    s.pop()
    s.popleft()
    le -= 2
  elif s[0] == "x":
    s.popleft()
    cnt += 1
    le -= 1
  elif s[-1] == "x":
    s.pop()
    cnt += 1
    le -= 1
  else:
    print(-1)
    break
else:
  print(cnt)