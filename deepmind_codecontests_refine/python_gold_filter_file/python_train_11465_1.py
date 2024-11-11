import math

t = int(input())

while(t):
    d = int(input())
    disc = d*d - 4*d
    if disc < 0 :
        print('N')
    else:
        print('Y', (d-math.sqrt(disc))/2, (d+math.sqrt(disc))/2)
    t=t-1