n,k=map(int,input().strip().split())
a=list(map(int ,input().strip().split()))

minimum=0
ans=0
a.sort()
for i in range(len(a)):
    if(abs(a[minimum])>abs(a[i])):
        minimum=i
    if (k>0):
        if(i+1==len(a)):
            if(k%2==1):
                a[minimum]*=-1
            k=0
        elif(a[i]<0):
            a[i]*=-1
            k-=1
        elif(a[i]>=0):
            if(k%2==1):
                a[minimum]*=-1
            k=0
for i in a:
    ans+=i
print(ans)
