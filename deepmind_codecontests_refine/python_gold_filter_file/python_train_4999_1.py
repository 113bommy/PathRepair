from collections import deque
d = deque()
for _ in range(int(input())):
  a = input()
  if "i" == a[0]: d.appendleft(int(a[7:]))
  elif "F" == a[6]: d.popleft()
  elif "L" == a[6]: d.pop()
  else:
    try: d.remove(int(a[7:]))
    except: pass
print(*d)
