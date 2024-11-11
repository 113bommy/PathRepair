n , m = input().split()
n, m = int(n) , int(m)

lt=[]

for i in range(1,n+1):
    if i%2==1:
        ct = ['#']*m
        lt.append(ct)
    else:
        k = i//2
        if k%2==0:
            ct = ['#'] + ['.']*(m-1)
            lt.append(ct)
        else:
            ct = ['.']*(m-1) + ['#']
            lt.append(ct)
for c in lt:
    print(*c, sep="")
