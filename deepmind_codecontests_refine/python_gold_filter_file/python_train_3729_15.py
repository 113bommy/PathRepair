import bisect
import heapq
n,m=map(int,input().split())
py_i=[[int(x) for x in input().split()] for _ in range(m)]
y_p=[[] for i in range(n+1)]
for x,y in sorted(py_i):
    #print(x)
    y_p[x].append(y)
for x,y in py_i:
    z=bisect.bisect_right(y_p[x],y)
    print("%06d"%x+"%06d"%z)

#print(y_p)