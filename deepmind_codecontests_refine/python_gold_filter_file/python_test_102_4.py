# cook your dish here

def fun(n,m,s):
    import sys
    yo = sys.maxsize
    
    
    l = len(s)
    ver,hor = 0, 0
    
    lmax = 0; rmax = 0
    umax = 0; dmax = 0
    
    for ch in s:
        if ch == 'L':
            hor-= 1
        if ch == 'R':
            hor+= 1
        if ch == 'U':
            ver-= 1
        if ch == 'D':
            ver+= 1
            
        lmax = min(lmax, hor)
        umax = min(umax, ver)
        rmax = max(rmax, hor)
        dmax = max(dmax, ver)
        
        if (rmax - lmax) >= m or (dmax-umax )>= n:
            if ch == 'U':
                umax+=1
            if ch == 'D':
                dmax-=1
            if ch == 'L':
                lmax+=1
            if ch == 'R':
                rmax-=1
            break
    ansy = ((0-lmax) + (m - rmax))//2
    ansx = ((0-umax) + (n-dmax))//2;
    
    return [ansx+1,ansy+1]
            
                
t = int(input())
for i in range(t):
    # n = int(input())
    # t = input()
    n,m = map(int,input().split())
    # s = list(map(int,input().split()))
    s = input()
    ans = fun(n,m,s)
    print(*ans)
    # print()