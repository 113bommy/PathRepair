t = int(input())
for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    s = sum(a)
    ans = 0
    ed = a.count(1)
    nu = a.count(0)
    if nu == 0 and ed == 0:
        print(0)
    elif nu > 0 and ed == 0:
        print(0)
    elif nu == 0 and ed > 0:
        print(ed)
    elif nu > 0 and ed > 0:
        print(ed * (2**nu))