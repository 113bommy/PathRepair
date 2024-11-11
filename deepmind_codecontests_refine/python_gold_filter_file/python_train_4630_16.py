n=int(input())
l = [int(x) for x in input().split()]
a = l.count(1)
b = l.count(2)
c = l.count(3)
d = min(a, b, c)
if(d == 0):
    print("0")
else:
    print(d)
    while(d>0):
        e = l.index(1)
        f = l.index(2)
        g = l.index(3)
        l[e]=0
        l[f] = 0
        l[g] = 0
        print(e+1, f+1, g+1)
        d = d -1