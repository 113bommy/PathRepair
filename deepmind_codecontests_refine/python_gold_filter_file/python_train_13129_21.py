import math
n = int(input())

for i in range(n):
    count,start,end,step = map(int, input().split())
    start -= 1
    end -= 1
    d = abs(start - end)
    if d % step == 0:
        print( int(d/step) )
    else:
        arr = []

        dLeft = start
        leftSteps = math.ceil(dLeft / step)
        leftSteps += int(end / step)
        if end % step == 0:
            arr.append(leftSteps)

        dRight = abs(count - start)
        rightSteps = math.ceil(dRight / step)
        rightSteps += int((count-end-1) / step)
        if (count-end-1) % step == 0:
            arr.append(rightSteps)


        if len(arr) == 0:
            print(-1)
        else:
            print(min(arr))
