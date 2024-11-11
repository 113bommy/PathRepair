import math
for _ in range(int(input())):
    n = 2*int(input())
    #print(1+2*((n-4)/4)*(math.sin(((n-2)*(math.pi)/n)-(math.pi/2))))
    print(1/(2*math.sin(math.pi/(2*n))))