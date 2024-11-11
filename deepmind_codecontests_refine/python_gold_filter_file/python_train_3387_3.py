n,k=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
i=0
j=0
Ansp=[0,0]
zcnt=0
max=0

while i<=n-1 :
    while j<n :
        if zcnt>=k and a[j]==0 :break
        j+=1
        if not a[j-1]:
            zcnt+=1
            if zcnt>k :
                j-=1
                zcnt-=1
                break
    l=j-i
    #print(i,j,zcnt)
    if l>max :
        max=l
        Ansp=[i,j]
    if not a[i] :
        zcnt-=1
    i+=1
    

for i in range(Ansp[0],Ansp[1]) :
    a[i]=1
    
print(max)
print(" ".join(map(str,a)))