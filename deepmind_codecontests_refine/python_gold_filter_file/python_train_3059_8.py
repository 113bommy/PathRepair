n=int(input())
ro=0

for i in range(2,n):
    c=1
    for h in range(1,n):
        c=(c*i)%n
        if(c%n==1):
            if(h==n-1):
                ro+=1
            else:
                break
print(ro+(n==2))