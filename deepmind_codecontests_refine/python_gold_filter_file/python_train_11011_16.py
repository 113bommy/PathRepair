n,k=map(int,input().split())
a=list(map(int,input().split()))

for _ in range(min(k,100)):
    s=[0 for _ in range(n)]
    e=[0 for _ in range(n)]
    for i in range(n):
        d=a[i]
        s[max(0,i-d)]+=1
        e[min(n-1,i+d)]+=1
    a[0]=s[0]
    for i in range(1,n):
        s[i]=s[i-1]+s[i]
        e[i]=e[i-1]+e[i]
        a[i]=s[i]-e[i-1]

print(*a)