A,B,C,D,E,F = map(int,input().split())
xmax = 100*A
kmax = 0
for n in range(31):
    for m in range(31):
        x = 100*(n*A+m*B)
        ymax = min((n*A+m*B)*E,F-100*(n*A+m*B))
        for k in range(ymax,ymax-C-1,-1):
            t = 0
            flag = 0
            while k-t*D>=0:
                if (k-t*D)%C==0:
                    flag = 1
                    break
                t += 1
            if flag==1:
                if kmax*(x+k)<k*(xmax+kmax):
                    xmax = x
                    kmax = k
print(xmax+kmax,kmax)