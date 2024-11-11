import math
t1,t2 = map(int, input().split())
c1,c2 = map(int, input().split())
d1,d2 = map(int, input().split())

x = [(c1*t1, c2*t2),(d1*t1, d2*t2)]

x.sort(reverse=True)

if x[0][0]+x[0][1] == x[1][0]+x[1][1]:
    print("infinity")
elif x[0][0]+x[0][1] > x[1][0]+x[1][1]:
    print(0)
else:
    n = (x[0][0]-x[1][0]+0.0)/(x[1][0]+x[1][1]-x[0][0]-x[0][1])
    m = math.ceil(n)
    if math.floor(n) == m:
        print(2*m)
    else:
        print(2*m-1)