t = int(input())
for i in range(t):
    n = int(input())
    l = []
    o = []
    e = []
    for i in range(1,n+1):
        if(i%2!=0):
            o.append(i)
        elif(i%2==0):
            e.append(i)
    o.sort(reverse = True)
    if(n < 4):
        print(-1)
    elif(n>=4):
        e.remove(4)
        o.append(4)
        op = o + e
        print(*op)
    
    