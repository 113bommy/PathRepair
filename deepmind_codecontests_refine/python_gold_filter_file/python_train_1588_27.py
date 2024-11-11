import math
for _ in range(int(input())):
    n = int(input())
    r = 1/(2*math.tan((360/(2*2*n))*(math.pi/180)))
    R = 1/(2*math.sin((360/(2*2*n))*(math.pi/180)))
    print((r*2))