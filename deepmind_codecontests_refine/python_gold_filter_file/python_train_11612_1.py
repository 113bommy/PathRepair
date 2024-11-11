#import sys
#sys.stdin = open('in', 'r')
#n = int(input())
#a = [int(x) for x in input().split()]
h1,h2 = map(int, input().split())
a,b = map(int, input().split())

incperday = (a-b)*12
if h1 + 8*a >= h2:
    print (0)
elif incperday <= 0:
    print (-1)
else:
    h11 = h1 + 8*a - 12*b
    if h11 + 12*a >= h2:
        print(1)
    else:
        days = (h2 - h11 - 12*a) // incperday
        days += 2 if (h2 - h11 - 12*a) % incperday > 0 else 1
        print (days)
    
