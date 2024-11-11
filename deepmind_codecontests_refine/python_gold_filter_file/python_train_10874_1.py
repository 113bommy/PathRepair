n,h=map(int,input().split())
a = list(map(int, input().split()))
mod=1000000007
for i in range(0,n):
    a[i]=h-a[i]
ans=1
flag=0
if(n==1):
    if((a[0]==0)|(a[0]==1)):
        print(1)
    else:
        print(0)
else:
    if((a[0]==0)|(a[0]==1)):
        for i in range(1,n):
            k=a[i]-a[i-1]
            if((k<-1)|(k>1)):
                print(0)
                exit(0)
            elif(k==1):
                if(a[i]>1):
                    flag=flag+1
                continue
            elif(k==0):
                ans=(ans*(a[i-1]+1))%mod
            elif(k==-1):
                ans=(ans*(a[i-1]))%mod
                if(a[i]>0):
                    flag=flag-1
        if(flag!=0):
            print(0)
        else:
            print(ans)
    else:
        print(0)
