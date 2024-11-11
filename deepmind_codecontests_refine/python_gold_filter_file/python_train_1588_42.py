import math
for _ in range(int(input())):
    n = int(input())
    n = 2*n
    #print(n)
    
    ans = 1/(math.tan(math.pi/n))
    print((ans))
