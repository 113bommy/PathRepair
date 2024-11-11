from collections import deque

n, q = [int(_) for _ in input().split()]
processes = deque([tuple(input().split()) for i in range(n)])

time = 0
while processes:
    process = processes.popleft()

    if int(process[1]) <= q:
        time += int(process[1])
        print(process[0], time)

    else:
        time += q
        processes.append((process[0], int(process[1]) - q))

