n= int(input())
a= list(map(int,input().split()))
if n==1 or n==2:
    print(n)
else:
    m = 2
    maxi=2
    j=2
    while j<n :
        if a[j]==a[j-1]+a[j-2]:
            m+=1
            if m>= maxi:
                maxi=m
        else:
            m=2
        j+=1
    print(maxi)
            
        
