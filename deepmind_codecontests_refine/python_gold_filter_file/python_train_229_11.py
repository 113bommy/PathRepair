t = int(input())
 
while(t):
    n = int(input())
    p = [0]
    c = [0]
    l = []
    flag = 1
    for i in range(1,n+1):
        l = [int(x) for x in input().split()]
        p.append(l[0])
        c.append(l[1])
        if 0 > min(p[i]-p[i-1],c[i]-c[i-1],p[i]-p[i-1]-c[i]+c[i-1]):
            flag = 0
       
    if(flag == 1):    
        print("YES")
    else:
        print("NO")
    t-=1