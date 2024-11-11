n=int(input())
a=[int(x) for x in input().split()]
l=[1 for i in range(n)]
r=[1 for i in range(n)]
for i in range(1,n):
    if a[i]>a[i-1]:
        l[i]=l[i-1]+1
for i in range(n-2,0,-1):
    
    if a[i]<a[i+1]:
        r[i]=r[i+1]+1
maxi=-9999999999

p=max(max(l),max(r))
for i in range(n):
    if i==0:
        maxi=max(maxi,r[i+1])
    elif i==n-1:
        maxi=max(maxi,l[i-1])
    else:
        if a[i-1]>=a[i+1]:
            maxi=max(maxi,max(l[i-1],r[i+1]))
        else:    
            maxi=max(maxi,l[i-1]+r[i+1])
           
print(max(p,maxi))   