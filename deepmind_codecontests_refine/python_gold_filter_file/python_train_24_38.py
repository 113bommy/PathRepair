import sys

t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    a=list(map(int,(sys.stdin.readline()).split()))
    counter=0
    for i in range(n-1):
        su=a[i]+a[i+1]
        if su <=a[n-1]:
            print('{} {} {}'.format(i+1,i+2,n))
            counter=1
            break
    if counter==0:
        print(-1)


