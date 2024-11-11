from collections import deque
k=int(input())
d=deque(range(1,10))

for i in range(k):
    x=d.popleft()
    if x % 10 != 0:
        d.append(10*x + x%10 -1)
    d.append(10*x + x%10)
    if x%10 != 9:
        d.append(10*x + x%10 +1)

print(x)