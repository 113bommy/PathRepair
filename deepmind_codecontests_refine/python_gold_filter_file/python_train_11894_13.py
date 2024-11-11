from collections import deque
for _ in range(int(input())) :
    n = int(input())
    if(n < 4) :
        print(-1)
        continue
    else :
        dq = deque([2,4,1,3])
        for i in range(5, n + 1) :
            if(i % 2 == 0) : dq.append(i)
            else : dq.appendleft(i)
        print(*dq)
