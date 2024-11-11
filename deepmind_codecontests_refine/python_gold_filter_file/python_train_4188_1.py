for cases in range(int(input())):
    n=int(input())
    flag=0
    zero=0
    l=list(map(int,input().split()))
    max1=0
    maxend=0
    count=0
    maxc=0
    for i in range(0,n):
            
        maxend=maxend+l[i]
        count+=1
        if(max1<maxend):
            max1=maxend
            maxc=count

        if(maxend<=0):
            maxend=0
            count=0

        
    max2=sum(l)
    if(max2>max1):
        print("YES")
    elif(max2==max1 and maxc==n):
        print("YES")
    else:
        print("NO")
            
    
    
