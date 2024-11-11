n=list(map(int,input().split()))
sum=0
for i in range(n[0]):
    x=list(map(int,input().split()))
    f=0
    for i in range(2*n[1]):
        if x[i]==1:
            f=1
        if (i+1)%2==0:
            if f==1:
                sum+=1
                f=0
print(sum)