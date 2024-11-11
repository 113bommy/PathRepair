testcases = int(input())
for i in range(testcases):
    n = int(input())
    p = []
    r = []
    l = []
    for i in range(1,n+1):
        p.append(2**i)
    r.append(p[-1])
    p.pop(-1)
    for i in range((n//2)-1):
        r.append(p[0])
        p.pop(0)
    print(sum(r)-sum(p))