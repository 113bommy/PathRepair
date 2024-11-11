# cook your dish here
import sys
for _ in range(int(sys.stdin.readline())):
    n = int(sys.stdin.readline())
    a = []
    for _  in range(n):
        a.append(list(map(int,sys.stdin.readline().split())))
    d = [[10**19,10**19,10**19] for _ in range(n)]
    d[0][0]=0
    d[0][1]=a[0][1]
    d[0][2]=a[0][1]*2
    for i in range(1,n):
        for j in range(3):
            for k in range(3):
                if a[i][0]+j != a[i-1][0]+k:
                    d[i][j] = min(d[i-1][k]+a[i][1]*j,d[i][j])
    print(min(d[n-1]))
                    