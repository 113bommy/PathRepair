n,k = map(int,input().split())
c = k - (n//2 - 1)
l = []
if c<=0 or n == 1:
    if n == 1 and k == 0:
        print(2)
    else:
        print(-1)
else:
    i = 1
    if n == 1:
        l.append(c)
    else:
        l.append(c)
        l.append(2*c)
        i = 2*c + 1
        while 1:
            if len(l) == n:
                break
            if i+1!=l[0] and i+1 != l[1]:
                l.append(i)
                i+=1
            else:
                i+=2

    print(*l)
    
    
    
