n,m=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
maxa,maxi=0,0
minrem=n
for i in range(len(a)):
    if(n%a[i]<minrem):
        maxi=i
        maxa=n//a[i]
        minrem=n%a[i]

print(maxi+1,maxa)        
