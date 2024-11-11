import collections
import sys

n,q = map(int,input().split())
data = [[i for i in input().split()]for i in range(n)]
time = 0
while data:
    task = data[0]
    del data[0]
    if int(task[1]) <= q:
        time += int(task[1])
        print(task[0],time)
      
    else:
        time += q
        task[1] = str(int(task[1]) - q)
        data.append(task)