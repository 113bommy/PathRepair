t = int(input())
while t:
    t-=1
    n = int(input())
    arr = [int(i) for i in input().split()]
    o = arr.count(1)
    z = arr.count(0)
    if z>0:
        print(o + o*((2**z)-1))
    else:
        print(o)