
def go():
    from sys import stdin
    from heapq import heappush, heappop
    b = 0
    p = []
    z = 0
    res = []
    n, *L = stdin.read().splitlines()
    n = int(n)
    for x in L:
        a = x.split()
        if a[0][0] == 'r':
            if not p:
                res.append('insert 45')
                z+=1
            else:
                heappop(p)
                
                
        elif a[0][0] == 'g':
            b = int(a[1])
            while p and p[0] < b:
                res.append('removeMin')
                z+=1
                heappop(p)
            if not p or p[0] > b:
                res.append('insert '+a[1])
                z+=1
                heappush(p, b)
        else:
            heappush(p, int(a[1]))
        res.append(x)
        z+=1
    print(z)
                    
    print('\n'.join(res))
                
go()
    
