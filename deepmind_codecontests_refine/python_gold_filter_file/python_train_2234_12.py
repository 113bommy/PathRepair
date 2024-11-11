n,m=[int(i) for i in input().split()]
i=1
b=m
if m>n:
    print(-1)
else:
    while m<n/2:
        m=b*i
        i+=1
    print(m)