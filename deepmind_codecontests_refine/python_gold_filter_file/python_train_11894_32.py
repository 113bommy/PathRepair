for i in range(int(input())):
    n=int(input())
    if n<=3:
        print(-1)
    else:
        l = []
        for i in range(n,0,-1):
            if i%2 != 0:
                l.append(i)
        l.append(4)
        l.append(2)
        for i in range(6,n+1,2):
            l.append(i)
            
       
        print(*l)