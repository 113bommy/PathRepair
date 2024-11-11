n,k=map(int,input().split())
a=zip( list(map(int,input().split())),range(0,n) )
a=sorted(a)
i=0;start=[0]*n;count=[0]*n
for j in range(1,n):
    while i<j and (count[i]==k or a[i][0]+1!=a[j][0]):
        i+=1
    if i==j or a[0][0]!=0:
        print(-1)
        exit(0)
    start[j]=i
    count[j]+=1
    count[i]+=1
print(n-1)                         
for k in range(1,n):
    print(a[start[k]][1]+1,a[k][1]+1)