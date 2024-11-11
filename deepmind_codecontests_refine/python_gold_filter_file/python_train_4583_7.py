import collections

dq = collections.deque()
N, Q = map(int, input().split())
for i in range(N):
    name, time = input().split()
    dq.append((name, int(time)))
total_time = 0
while dq:
    name, time = dq.popleft()
    total_time += min(Q, time)
    if time <= Q:
        print(name, total_time)
    else:
        dq.append((name, time-Q))