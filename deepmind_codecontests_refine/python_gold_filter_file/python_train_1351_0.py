import math
n = int(input())
last = [-1] * 5
At = -1
Al = -1
Bt = -1
Bl = -1

for _ in range(n):
    
    l = list(map(int, input().split()))
    if last[2] != l[2] or last[1] == -1 or last[1] == l[1]:
        last = l
    elif last[1] != l[1]:
        len=math.sqrt((last[3] - l[3])**2 + (last[4] - l[4])**2)
        tim= l[0] - last[0]
        if l[2] == 0:
            if Al <= len:
                Al = len
                At = tim
        elif l[2] == 1:
            if Bl <= len:
                Bl = len
                Bt = tim
    last = l

if Al != -1:
    print("{0:.10f}".format(round(Al,10)), end = " ")
    print("{0:.10f}".format(At/60))
else:
    print("-1 -1")
if Bl != -1:
    print("{0:.10f}".format(round(Bl,10)), end = " ")
    print("{0:.10f}".format(Bt/60))
else:
    print("-1 -1")