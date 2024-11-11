n,k=map(int,input().split())

if(k==0):
    print("1",end="")
    for i in range(2,2*n+1):
        print(" "+str(i),end="")
    print()

elif(2*k==n):
    i=n-(k//2)
    j=n+(k//2)
    if(j-i!=k):
        j+=1
    print(i,j,end="")
    start=1
    end=2*n
    while(start<end):
        if(start==i or start==j):
            start+=1
            continue
        if(end==j or end==i):
            end-=1
            continue
        print(" "+str(end),str(start),end="")
        start+=1
        end-=1
    print()
else:
    L=list(range(1,2*n+1))
    print("1 ",end=str(k+1))
    for i in range(2*n,0,-1):
        if(i==1 or i==k+1):
            continue
        print(" "+str(i),end="")
    print()

