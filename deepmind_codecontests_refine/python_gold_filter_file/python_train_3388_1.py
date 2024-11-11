n,k=map(int,input().split())
b=list(map(int,input().split()))
c=[0]
for j in range(n):
    if b[j]==0:
        c.append(j)
j=0
strt=0
m=0
q=0
s=0
p=0
 
while(j<n):
    if b[j]==0:
        p+=1
        if p>k:
            if q!=0:
                s+=1
            q+=1
            s+=-(c[q]-c[q-1])
            strt=c[q]+1
            p-=1
        else:
            s+=1
    else:
        s+=1
    if s>=m:
        m=s
        x=strt
        y=j
    j+=1
j=x
while(j<=y):
    b[j]=1
    j+=1
print(m)
print(*b)