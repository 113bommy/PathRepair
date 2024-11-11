

n,m=list(map(int,input().split()))
y=[(2*n)-1,-1,2*n,0]
k=2
count=0
t=0
i=-1
while t<m:
    i+=1
    if (y[i%4]+k)<=m:
        print(y[i%4]+k,end=' ')
        count+=1
        t+=1
    else:
        count+=1
    if count==4:
        k+=2
        count=0
    else:
        continue
    
