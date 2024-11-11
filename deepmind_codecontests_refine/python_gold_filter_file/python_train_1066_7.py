def main():
    n, x, m = [int(a) for a in input().split()]
    lrs = []
    
    l_s = int(1e9 + 5)
    r_s = -99
    for mi in range(m):
        li, ri = [int(a) for a in input().split()]
        lrs.append([li, ri])
            
    # print(lrs)
    
    ans = 1
    # search interval
    for mi in range(m):
        if (lrs[mi][0] <= x) and (lrs[mi][1] >= x):
            l_s = min(lrs[mi][0], l_s)
            r_s = max(lrs[mi][1], r_s)

        if (lrs[mi][1] <= r_s) and (lrs[mi][1] >= l_s):
            l_s = min(lrs[mi][0], l_s)
            r_s = max(lrs[mi][1], r_s)
        elif (lrs[mi][0] <= r_s) and (lrs[mi][0] >= l_s):
            l_s = min(lrs[mi][0], l_s)
            r_s = max(lrs[mi][1], r_s)
        else:
            pass
        
        #print(r_s)
        #print(l_s)
    ans = max(ans, (r_s - l_s + 1))
        
    print(ans)
            

t = int(input())

for _ in range(t):
    main() 