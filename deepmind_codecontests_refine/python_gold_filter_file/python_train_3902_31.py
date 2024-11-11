n,b=map(int,input().split())
k=1
for i in range(1,n+1):
    if i%2==0:
        if k==1:
            print("."*(b-1),"#",sep="")
        else:
            print("#","."*(b-1),sep="")
        k=-k
    else:
        print("#"*b)