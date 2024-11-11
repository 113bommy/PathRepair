import math

t  = int(input())

for counter in range(t):
    d = int(input())
    try:
        if d == 0:
            print('Y 0.0 0.0')
        else:
            a = 0.0
            a = (float(d)+math.sqrt(float(d**2) - 4*d))/2
            b = a/(a-1)
            if a < 0 or b < 0:
                print('N')
            else:
                print('Y ' + str(a) + ' ' + str(b))
    except:
        print('N')
        
