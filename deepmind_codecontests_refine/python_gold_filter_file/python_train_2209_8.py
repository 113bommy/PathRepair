t=int(input())
for i in range(t):
    n=int(input())
    m=0
    while n>=10:
        r=n%10
        n=int(n/10)
        m=m+(n*10)
        n=n+r
    print(m+n)