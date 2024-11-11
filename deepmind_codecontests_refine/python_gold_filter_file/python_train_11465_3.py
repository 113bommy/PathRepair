T = int(input())
for _ in range(T):
    d = int(input())
    if d==0:
        print("Y 0.000000000 0.000000000")
        continue
    l = 0.0
    h = d
    EPS = 0.000000000001
    b = True
    while h-l>EPS and b:
        m = (l+h)/2
        if abs(d-(m+(d/m)))<EPS and abs((m*(d/m))-(m+(d/m)))<EPS:
            print('Y {0} {1}'.format(m,(d-m)))
            b = not b
        elif (m+(d/m))<d:
            l = m
        else:
            h = m
    if b:
        print("N")