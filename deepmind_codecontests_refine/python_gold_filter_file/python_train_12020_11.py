n,m,a,b=map(int,input().split())
l=[]
for i in range(0,n+1):
    for j in range(0,n+1):
        if(i+j*m>=n):
            l.append(a*i+b*j)
print(min(l))