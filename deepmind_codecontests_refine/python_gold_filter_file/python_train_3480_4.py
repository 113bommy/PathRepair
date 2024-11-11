def floor(x):
    if (x == int(x)):
        return int(x)
    else:
        return int(x) + 1
a = input()
a = list(a.split(' '))
a = list(map(int,a))
ts = floor(a[1] / a[3])
tb = 0
#print(ts)
tb += a[2] // (a[0] - 1)
ts -= tb * a[0]
a[2] -= tb * (a[0] - 1)
#print(ts)
if (ts <= 0):
    ts += tb * a[0]
    #print(ts)
    print(floor(a[1] / (a[0] * a[3])))
else:
    tb += 1
    ts -= a[2] + 1
    if (ts <= 0):
        print(int(tb))
    else:
        tb += ts
        print(int(tb))
 
