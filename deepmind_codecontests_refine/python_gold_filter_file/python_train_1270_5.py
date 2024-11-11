import sys
# input = sys.stdin.buffer.readline
input = sys.stdin.readline

from collections import deque
q = int(input())
for _ in range(q):
    n = int(input())
    x = list ( map(int,input().split()))
    # s=set()
    shortes =9999999999
    dic ={}
    # dq = deque()
    for i in range(n):
        if x[i] in dic.keys():
            if i - dic[x[i]] <shortes:
                shortes = i-dic[x[i]]
                # print(i,x[i])

        dic[x[i]] = i
        
        # dq.appendleft(x)
        # s.add(x)
    
    # print("isisis")
    if (shortes==9999999999):
        print(-1)
    else:
        print(shortes+1)
    
    