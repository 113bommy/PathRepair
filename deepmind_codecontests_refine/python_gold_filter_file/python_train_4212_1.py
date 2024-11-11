n=int(input())
a=list(map(float,input().split()))
m=max(a)
if m>=0.5:
    print(m)
elif len(a)==1:
    print(a[0])
else:
    a.sort()
    b=[1-a[i] for i in range(len(a))]
    m=0
    for i in range(n):
        sum=0
        for k in range(n-i-1,n):
            prod=1
            for j in range(n-i-1,n):
                if k!=j:
                    prod=prod*b[j]
                else:
                    prod=prod*a[k]
            sum=sum+prod
        m=max(m,sum)
    print(m)