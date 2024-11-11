import sys
import math
n = sys.stdin.readline()
n = n.replace('\n','')
n = int(n)
m = int(math.ceil(n/2))
l = sys.stdin.readline()
l = l.split(' ')
l[-1] = l[-1].replace('\n','')
for i in range(len(l)):
    l[i] = int(l[i])
p = 0
n = 0
for i in range(len(l)):
    if l[i] > 0:
        p+=1
    elif l[i]<0:
        n+=1
if p >= m:
    print(1)
elif n >=m:
    print(-1)
else:
    print(0)